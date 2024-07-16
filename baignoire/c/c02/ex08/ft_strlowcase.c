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
	int		i;
	char	*s;

	s = str;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			s[i] = s[i] + 32;
		i++;
	}
	return (s);
}
