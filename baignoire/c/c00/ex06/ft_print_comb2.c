#include <unistd.h>

void		ft_putchar(char c);
void		ft_print_number(int n);
void		ft_print_comb2(void);

int	main(void)
{
	ft_print_comb2();
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int n)
{
	ft_putchar(n / 10 + '0');
	ft_putchar(n % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	pair1;
	int	pair2;

	pair1 = 0;
	while (pair1 <= 98)
	{
		pair2 = pair1 + 1;
		while (pair2 <= 99)
		{
			ft_print_number(pair1);
			ft_putchar(' ');
			ft_print_number(pair2);
			if (!(pair1 == 98 && pair2 == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			pair2++;
		}
		pair1++;
	}
}
