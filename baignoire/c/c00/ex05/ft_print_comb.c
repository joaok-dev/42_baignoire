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
	int	i;
	int	j;
	int	k;

	i = 48;
	while (i < 56)
	{
		j = i + 1;
		while (j < 57)
		{
			k = j + 1;
			while (k < 58)
			{
				ft_putchar(i);
				ft_putchar(j);
				ft_putchar(k);
				if (i != 55 || j != 56 || k!= 57)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
