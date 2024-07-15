#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

int	is_valid_base(char *base)
{
	char	seen[256] = {0};
	char	*b;

	b = base;
	if (ft_strlen(base) < 2)
		return (0);
	while (*b)
	{
		if (*b == '+' || *b == '-' || (*b >= 9 && *b <= 13) || *b == 32)
			return (0);
		if (seen[(unsigned char)*b])
			return (0);
		seen[(unsigned char)*b] = 1;
		b++;
	}
	return (1);
}

int	get_index_in_base(char c, char *base)
{
	char	*b;

	b = base;
	while (*b)
	{
		if (*b == c)
			return (b - base);
		b++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_size, result, sign, index;

	if (!is_valid_base(base))
		return (0);
	base_size = ft_strlen(base);
	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str)
	{
		index = get_index_in_base(*str, base);
		if (index == -1)
			break ;
		result = result * base_size + index;
		str++;
	}
	return (result * sign);
}

int	main(void)
{
	printf("Result: %d\n", ft_atoi_base("11111111", "01"));
	printf("Result: %d\n", ft_atoi_base("255", "0123456789"));
	printf("Result: %d\n", ft_atoi_base("FF", "0123456789ABCDEF"));
	printf("Result: %d\n", ft_atoi_base("eff", "poneyvif"));
	printf("Result: %d\n", ft_atoi_base("-FF", "0123456789ABCDEF"));
	return (0);
}
