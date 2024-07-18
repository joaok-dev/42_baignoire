#include <stdio.h>

int		ft_str_is_printable(char *str);

int	main(void)
{
	char	str1[] = "Hello, World!";
	char	str2[] = "Hello\nWorld!";
	char	str3[] = "";

	printf("Test 1: %s - Result: %d\n", str1, ft_str_is_printable(str1));
	printf("Test 2: %s - Result: %d\n", str2, ft_str_is_printable(str2));
	printf("Test 3: \"%s\" - Result: %d\n", str3, ft_str_is_printable(str3));
	return (0);
}

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!(*str >= ' ' && *str <= '~'))
			return (0);
		str++;
	}
	return (1);
}
