#include <stdlib.h>

/*
 * ft_is_delimiter - Checks if a character is a delimiter
 *
 * This function iterates through the charset string to determine
 * if the given character is a delimiter.
 *
 * @c: The character to check
 * @charset: String containing delimiter characters
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 *
 * Flow:
 * 1. Iterate through each character in charset
 * 2. If a match is found, return 1
 * 3. If no match is found after full iteration, return 0
 */
int	ft_is_delimiter(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

/*
 * ft_count_splits - Counts the number of words in the input string
 *
 * This function iterates through the input string, counting the
 * number of words separated by delimiters defined in charset.
 *
 * @str: The input string to be split
 * @charset: String containing delimiter characters
 *
 * Return: The number of words in the input string
 *
 * Flow:
 * 1. Initialize word count to 0
 * 2. Skip leading delimiters
 * 3. If a non-delimiter is found, increment count and skip the word
 * 4. Repeat steps 2-3 until end of string is reached
 */
int	ft_count_splits(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_delimiter(*str, charset))
			str++;
		if (*str)
			count++;
		while (*str && !ft_is_delimiter(*str, charset))
			str++;
	}
	return (count);
}

/*
 * ft_create_split - Extracts a single word from the input string
 *
 * This function allocates memory for a word and copies it from the input string.
 * It advances the input string pointer to the next word.
 *
 * @str: Pointer to the current position in the input string
 * @charset: String containing delimiter characters
 *
 * Return: Pointer to the extracted word, or NULL if allocation fails
 *
 * Flow:
 * 1. Skip leading delimiters
 * 2. Mark the start of the word
 * 3. Find the end of the word
 * 4. Allocate memory for the word
 * 5. Copy the word to the allocated memory
 * 6. Null-terminate the word
 */
char	*ft_create_split(char **str, char *charset)
{
	char	*split_start;
	char	*split;
	char	*split_ptr;

	while (**str && ft_is_delimiter(**str, charset))
		(*str)++;
	split_start = *str;
	while (**str && !ft_is_delimiter(**str, charset))
		(*str)++;
	split = malloc((*str - split_start + 1) * sizeof(char));
	if (!split)
		return (NULL);
	split_ptr = split;
	while (split_start < *str)
		*split_ptr++ = *split_start++;
	*split_ptr = '\0';
	return (split);
}

/*
 * ft_free_split - Frees the memory allocated for the split strings
 *
 * This function iterates through the array of strings, freeing
 * each individual string and then the array itself.
 *
 * @split: The array of strings to be freed
 *
 * Flow:
 * 1. Initialize a temporary pointer to the start of the array
 * 2. Iterate through the array, freeing each string
 * 3. Free the array itself
 */
void	ft_free_split(char **split)
{
	char	**tmp;

	tmp = split;
	while (*tmp)
		free(*tmp++);
	free(split);
}

/*
 * ft_split - Splits a string into an array of substrings
 *
 * This function splits the input string into an array of substrings
 * based on the delimiters defined in charset.
 *
 * @str: The input string to be split
 * @charset: String containing delimiter characters
 *
 * Return: An array of strings (words), or NULL if allocation fails
 *
 * Flow:
 * 1. Count the number of words in the input string
 * 2. Allocate memory for the array of strings
 * 3. Extract each word and store in the array
 * 4. If any allocation fails, free all memory and return NULL
 * 5. Null-terminate the array of strings
 */
char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	**s;
	int		split_count;

	split_count = ft_count_splits(str, charset);
	split = malloc((split_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	s = split;
	while (split_count--)
	{
		*s = ft_create_split(&str, charset);
		if (!*s)
		{
			ft_free_split(split);
			return (NULL);
		}
		s++;
	}
	*s = NULL;
	return (split);
}
