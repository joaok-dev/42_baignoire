#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		++str;
	}
	return (number * sign);
}

int	main(void)
{
	char	str1[] = "   ---+--+1234ab567";
	char	str2[] = "42";
	char	str3[] = "    +987";
	char	str4[] = "   -  123";

	printf("String: '%s' -> Integer: %d\n", str1, ft_atoi(str1));
	printf("String: '%s' -> Integer: %d\n", str2, ft_atoi(str2));
	printf("String: '%s' -> Integer: %d\n", str3, ft_atoi(str3));
	printf("String: '%s' -> Integer: %d\n", str4, ft_atoi(str4));
	return (0);
}
