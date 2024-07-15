#include <stdio.h>

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	src[] = "Hello, World!";
	char	dest[20];
	unsigned int	n,	result;

	n = 10;
	result = ft_strlcpy(dest, src, n);
	printf("Destination: %s\n", dest);
	printf("Length of src: %u\n", result);
	return (0);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	n;
	char			*d, *s;

	n = size;
	d = dest;
	s = src;
	if (n != 0)
	{
		while (--n != 0 && *s != '\0')
			*d++ = *s++;
		*d = '\0';
	}
	while (*s != '\0')
		s++;
	return (s - src);
}
