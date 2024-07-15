#include <unistd.h>

void		ft_putchar(char c);
void		ft_print_numbers(void);

int	main(void)
{
	ft_print_numbers();
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	int	i;

	i = 48;
	while (i < 58)
	{
		ft_putchar(i);
		i++;
	}
}
