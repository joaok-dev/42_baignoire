#include <stdio.h>

int		ft_str_is_uppercase(char *str);

int	main(void)
{
	char	str1[] = "joaokennedy";
	char	str2[] = "JOAOKENNEDY";
	char	str3[] = "";

	printf("Test 1: %s - Result: %d\n", str1, ft_str_is_uppercase(str1));
	printf("Test 2: %s - Result: %d\n", str2, ft_str_is_uppercase(str2));
	printf("Test 3: \"%s\" - Result: %d\n", str3, ft_str_is_uppercase(str3));
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}
