#include <stdio.h>
#include <stdlib.h>

char		*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	src[] = "Joao Kennedy";
	char	*dest;

	dest = (char *)malloc((sizeof(src) / sizeof(src[0])) * sizeof(char));
	if (dest == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	printf("Source before copy: %s\n", src);
	printf("Destination before copy: %s\n", dest);
	ft_strcpy(dest, src);
	printf("Source after copy: %s\n", src);
	printf("Destination after copy: %s\n", dest);

	free(dest);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*d;

	d = dest;
	while ((*d++ = *src++) != '\0')
		;
	return (dest);
}
