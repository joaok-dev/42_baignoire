#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned	int nb)
{
	char			*d;
	char			*s;
	unsigned int	i;

	d = dest;
	s = src;
	i = 0;
	while (*d != '\0')
		d++;
	while (*s != '\0' && i < nb)
	{
		*d++ = *s++;
		i++;
	}
	*d = '\0';
	return (d);
}

int	main(void)
{
	char	dest[50] = "Hello, ";
	char	src[] = "world!";
	int		n = 3;

	ft_strncat(dest, src, n);
	printf("Concatenated string: %s\n", dest);
	return (0);
}
