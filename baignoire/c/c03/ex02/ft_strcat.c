#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

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

int	main(void)
{
	const char	*s1 = "Hello, ";
	const char	*s2 = "world!";
	char		*result;
	size_t		len1;
	size_t		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	result[0] = '\0';
	ft_strcat(ft_strcat(result, s1), s2);
	printf("Concatenated string: %s\n", result);
	free(result);
	return (0);
}
