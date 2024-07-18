#include <stdio.h>

char		*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	src[] = "Joao Kennedy";
	char	dest[20];

	ft_strncpy(dest, src, 14);

	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);

	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while(n--)
	{
		if (*s)
			*d++ = *s++;
		else
			*d++ = '\0';
	}
	return (dest);
}
