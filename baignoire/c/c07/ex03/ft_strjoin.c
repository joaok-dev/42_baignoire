#include <stdlib.h>

/* Calculates the length of a string */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

/* Concatenates string */
char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

/* Calculates total length of joined strings */
int	ft_total_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	sep_len;

	total_len = 0;
	sep_len = ft_strlen(sep);
	while (size--)
	{
		total_len += ft_strlen(*strs);
		if (size)
			total_len += sep_len;
		strs++;
	}
	return (total_len);
}

/* Joins an array of strings with a separator
   1. Calculate total length
   2. Allocate memory for joined string
   3. Concatenate strings with separator
   4. Return the joined string */
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strjoin;
	char	*ptr;
	int		total_len;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	total_len = ft_total_length(size, strs, sep);
	strjoin = (char *)malloc((total_len + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	ptr = strjoin;
	*ptr = '\0';
	while (size--)
	{
		ptr = ft_strcat(ptr, *strs++);
		if (size)
			ptr = ft_strcat(ptr, sep);
	}
	return (strjoin);
}
