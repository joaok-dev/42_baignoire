#include <stdio.h>

int		ft_str_is_numeric(char *str);

int	main(void)
{
	char	str1[] = "123456";
	char	str2[] = "42JoaoKennedy42";
	char	str3[] = "";

	printf("Test 1: %s - Result: %d\n", str1, ft_str_is_numeric(str1));
	printf("Test 2: %s - Result: %d\n", str2, ft_str_is_numeric(str2));
	printf("Test 3: \"%s\" - Result: %d\n", str3, ft_str_is_numeric(str3));
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] > 47 && str[i] < 58))
			return (0);
		i++;
	}
	return (1);
}
