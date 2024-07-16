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
	int		i;
	char	*s;

	s = str;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			s[i] = s[i] - 32;
		i++;
	}
	return (s);
}
