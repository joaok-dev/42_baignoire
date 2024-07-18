#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	c;
	int		i;

	c = '9';
	i = 0;
	while (i <=9)
	{
		ft_putchar(c - i);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
