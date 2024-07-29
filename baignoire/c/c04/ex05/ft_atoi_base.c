#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	char	*end;

	end = str;
	while (*end)
		end++;
	return (end - str);
}

int	is_valid_base(char *base)
{
	char	*b1;
	char	*b2;

	if (ft_strlen(base) < 2)
		return (0);
	b1 = base;
	while (*b1)
	{
		if (*b1 == '+' || *b1 == '-' || *b1 == ' '
			|| (*b1 >= '\t' && *b1 <= '\r'))
			return (0);
		b2 = b1 + 1;
		while (*b2)
		{
			if (*b1 == *b2)
				return (0);
			b2++;
		}
		b1++;
	}
	return (1);
}

char	*get_char_in_base(char c, char *base)
{
	while (*base && *base != c)
		base++;
	if (*base)
		return (base);
	return (NULL);
}

int	ft_atoi_base(char *str, char *base)
{
	int		result;
	int		sign;
	char	*base_end;

	if (!is_valid_base(base))
		return (0);
	result = 0;
	sign = 1;
	base_end = base + ft_strlen(base);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && get_char_in_base(*str, base))
	{
		result = result * (base_end - base) + (get_char_in_base(*str, base) - base);
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
