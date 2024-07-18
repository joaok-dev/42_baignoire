#include <stdio.h>

int		ft_str_is_lowercase(char *str);

int	main(void)
{
	char	str1[] = "joaokennedy";
	char	str2[] = "JoaoKennedy";
	char	str3[] = "";

	printf("Test 1: %s - Result: %d\n", str1, ft_str_is_lowercase(str1));
	printf("Test 2: %s - Result: %d\n", str2, ft_str_is_lowercase(str2));
	printf("Test 3: \"%s\" - Result: %d\n", str3, ft_str_is_lowercase(str3));
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}
