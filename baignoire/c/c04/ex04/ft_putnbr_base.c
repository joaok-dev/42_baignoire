#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	char	*b = base;

	if (ft_strlen(base) < 2)
		return (0);
	while (*b)
	{
		if (*b == '+' || *b == '-')
			return (0);
		if (seen[(unsigned char)*b])
			return (0);
		seen[(unsigned char)*b] = 1;
		b++;
	}
	return (1);
}

void	convert_and_print(unsigned int value, char *base, unsigned int base_size)
{
	if (value >= base_size)
		convert_and_print(value / base_size, base, base_size);
	ft_putchar(base[value % base_size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_size;
	unsigned int	abs_value;

	if (!is_valid_base(base))
		return ;
	base_size = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		abs_value = -nbr;
	}
	else
	{
		abs_value = nbr;
	}
	convert_and_print(abs_value, base, base_size);
}

int	main(void)
{
	ft_putnbr_base(255, "01");
	write(1, "\n", 1);
	ft_putnbr_base(255, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(255, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(255, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(-255, "0123456789ABCDEF");
	write(1, "\n", 1);
	return (0);
}
