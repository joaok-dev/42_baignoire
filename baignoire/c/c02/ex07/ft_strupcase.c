#include <stdio.h>

char		*ft_strupcase(char *str);

int	main(void)
{
	char	str1[] = "joao kennedy";

	printf("Original: %s\n", str1);
	printf("Uppercase: %s\n", ft_strupcase(str1));
	return (0);
}

char	*ft_strupcase(char *str)
{
	char	*s;

	s = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (s);
}
