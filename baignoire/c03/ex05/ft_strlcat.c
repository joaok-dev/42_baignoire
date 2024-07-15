#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len, src_len, n;
	char			*d, *s;

	d = dest;
	s = src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	dest_len = d - dest;
	n = size - dest_len;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (n == 0)
		return (dest_len + src_len);
	while (*s != '\0' && n-- > 1)
		*d++ = *s++;
	*d = '\0';
	return (dest_len + src_len);
}

int	main(void)
{
	char			dest[50] = "Hello, ";
	char			src[] = "world!";
	unsigned int	n;

	n = ft_strlcat(dest, src, sizeof(dest));
	printf("Concatenated string: %s\n", dest);
	printf("Total length: %u\n", n);
	char	dest2[15] = "Foo";
	char	src2[] = "Bar";
	n = ft_strlcat(dest2, src2, sizeof(dest2));
	printf("Concatenated string: %s\n", dest2);
	printf("Total length: %u\n", n);
	char	dest3[10] = "Test";
	char	src3[] = "12345";
	n = ft_strlcat(dest3, src3, sizeof(dest3));
	printf("Concatenated string: %s\n", dest3);
	printf("Total length: %u\n", n);
	return (0);
}
