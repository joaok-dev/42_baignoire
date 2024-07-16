#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(int *comb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(comb[i] + '0');
		i++;
	}
	if (comb[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	generate_combn(int *comb, int n, int index)
{
	int	i;

	if (index == n)
	{
		print_comb(comb, n);
		return ;
	}
	if (index == 0)
		i = 0;
	else
		i = comb[index - 1] + 1;
	while (i < 10)
	{
		comb[index] = i;
		generate_combn(comb, n, index + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[9];

	if (n > 0 && n < 10)
		generate_combn(comb, n, 0);
}

int	main(void)
{
	ft_print_combn(2);
	ft_putchar('\n');
	ft_print_combn(3);
	ft_putchar('\n');
	ft_print_combn(4);
	ft_putchar('\n');
	return (0);
}
