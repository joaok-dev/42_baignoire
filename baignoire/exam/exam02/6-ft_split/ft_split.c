#include <stdlib.h>

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	ft_word_count(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_whitespace(*str))
			str++;
		if (*str && !ft_is_whitespace(*str))
		{
			count++;
			while (*str && !ft_is_whitespace(*str))
				str++;
		}
	}
	return (count);
}

static char	*ft_word_dup(char *start, char *end)
{
	char	*word;
	char	*ptr;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	ptr = word;
	while (start < end)
		*ptr++ = *start++;
	*ptr = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**result;
	char	*start;
	int		words;

	words = ft_word_count(str);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	words = 0;
	while (*str)
	{
		while (*str && ft_is_whitespace(*str))
			str++;
		start = str;
		while (*str && !ft_is_whitespace(*str))
			str++;
		if (start != str)
			*result++ = ft_word_dup(start, str);
	}
	*result = NULL;
	return (result - words);
}
