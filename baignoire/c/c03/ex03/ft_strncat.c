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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src && nb > 0)
	{
		*ptr++ = *src++;
		nb--;
	}
	*ptr = '\0';
	return (dest);
}

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	n;

	s1 = "world!";
	s2 = "Hello, ";
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	n = 3;
	result = (char *)malloc((len1 + n + 1) * sizeof(char));
	if (!result)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	result[0] = '\0';
	ft_strncat(ft_strncat(result, s1, len1), s2, n);
	printf("Concatenated string: %s\n", result);
	free(result);
	return (0);
}
