#include <stdio.h>

char		*ft_strlowcase(char *str);

int	main(void)
{
	char	str1[] = "JOAO KENNEDY";

	printf("Original: %s\n", str1);
	printf("Uppercase: %s\n", ft_strlowcase(str1));
	return (0);
}

char	*ft_strlowcase(char *str)
{
	char	*s;

	s = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (s);
}
