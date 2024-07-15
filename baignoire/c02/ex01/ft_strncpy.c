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
	unsigned int	i;
	char			*d, *s;

	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		if (s[i] != '\0')
		{
			d[i] = s[i];
		}
		else
		{
			d[i] = '\0';
		}
		i++;
	}
	return (d);
}
