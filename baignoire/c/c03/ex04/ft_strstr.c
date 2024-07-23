#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*f;

	if (*to_find)
		return ((char *)str);
	while (*str)
	{
		s = str;
		f = to_find;
		while (*s && *f && (*s == *f))
		{
			s++;
			f++;
		}
		if (*f)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

int	main(void)
{
	char	*str = "Hello, World!";
	char	*to_find = "World";
	char	*result;

	result = ft_strstr(str, to_find);
	if (result)
		printf("Substring found at position: %ld\n", result - str);
	else
		printf("Substring not found.\n");
	return (0);
}
