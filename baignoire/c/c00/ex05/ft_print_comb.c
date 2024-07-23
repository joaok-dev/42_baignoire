#include <unistd.h>

void		ft_putchar(char c);
void		ft_print_comb(void);

int	main(void)
{
	ft_print_comb();
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	first_digit;
	int	second_digit;
	int	third_digit;

	first_digit = '0';
	while (first_digit <= '7' )
	{
		second_digit = first_digit + 1;
		while (second_digit < '8')
		{
			third_digit = second_digit + 1;
			while (third_digit < '9')
			{
				ft_putchar(first_digit);
				ft_putchar(second_digit);
				ft_putchar(third_digit);
				if (first_digit != '7' || second_digit != '8'
					|| third_digit!= '9')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				third_digit++;
			}
			second_digit++;
		}
		first_digit++;
	}
}
