#include <stdio.h>

int		ft_str_is_alpha(char *str);

int	main(void)
{
	char	str1[] = "JoaoKennedy";
	char	str2[] = "42Joao Kennedy 42";
	char	str3[] = "";

	printf("Test 1: %s - Result: %d\n", str1, ft_str_is_alpha(str1));
	printf("Test 2: %s - Result: %d\n", str2, ft_str_is_alpha(str2));
	printf("Test 3: \"%s\" - Result: %d\n", str3, ft_str_is_alpha(str3));
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!((*str >= 'A' && *str <= 'Z' ) || (*str >= 'a' && *str < 'z')))
			return (0);
		str++;
	}
	return (1);
}
