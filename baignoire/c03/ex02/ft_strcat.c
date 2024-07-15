#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	while (*d != '\0')
		d++;
	while (*s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (d);
}

int	main(void)
{
	char	dest[50] = "Hello, ";
	char	src[] = "world!";

	ft_strcat(dest, src);
	printf("Concatenated string: %s\n", dest);
	return (0);
}
