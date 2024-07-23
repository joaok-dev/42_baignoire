#include <stdlib.h>

/**
 * Determines if a character is considered a delimiter.
 * Delimiters are defined as space, tab, or newline.
 *
 * @param c The character to check.
 * @return 1 if the character is a delimiter, 0 otherwise.
 */
static int	ft_is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * Counts the number of words in a string.
 * A word is defined as a sequence of non-delimiter characters.
 *
 * @param str The input string to count words from.
 * @return The number of words in the string.
 */
static size_t	ft_count_words(char *str)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (ft_is_delimiter(*str))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/**
 * Extracts a single word from the input string.
 * Allocates memory for the word and copies it.
 * Advances the input string pointer to the next word.
 *
 * @param str_ptr Pointer to the current position in the input string.
 * @return Pointer to the extracted word, or NULL if allocation fails.
 */
static char	*ft_extract_word(char **str_ptr)
{
	char	*word_start;
	char	*word_end;
	char	*word;
	char	*word_ptr;

	while (ft_is_delimiter(**str_ptr))
		(*str_ptr)++;
	word_start = *str_ptr;
	while (**str_ptr && !ft_is_delimiter(**str_ptr))
		(*str_ptr)++;
	word_end = *str_ptr;
	word = (char *)malloc((word_end - word_start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word_ptr = word;
	while (word_start < word_end)
		*word_ptr++ = *word_start++;
	*word_ptr = '\0';
	return (word);
}

/**
 * Frees all allocated memory in case of an error.
 * Iterates through the array of strings, freeing each string,
 * then frees the array itself.
 *
 * @param split The array of strings to free.
 */
static void	ft_free_split(char **split)
{
	char	**current;

	if (!split)
		return ;
	current = split;
	while (*current)
	{
		free(*current);
		current++;
	}
	free(split);
}

/**
 * Splits a string into an array of words.
 * Words are separated by delimiters (space, tab, newline).
 * The resulting array is NULL-terminated.
 *
 * @param str The input string to split.
 * @return A NULL-terminated array of strings (words),
 * or NULL if allocation fails.
 */
char	**ft_split(char *str)
{
	char	**result;
	char	**current;
	size_t	word_count;

	if (!str)
		return (NULL);
	word_count = ft_count_words(str);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	current = result;
	while (word_count--)
	{
		*current = ft_extract_word(&str);
		if (!*current)
		{
			ft_free_split(result);
			return (NULL);
		}
		current++;
	}
	*current = NULL;
	return (result);
}
