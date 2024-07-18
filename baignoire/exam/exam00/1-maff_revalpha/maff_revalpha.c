#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	c;
	int		i;

	i = 0;
	while (i < 26)
	{
		c = 'z' - i;
		if (i % 2 == 0)
			ft_putchar(c);
		else
			ft_putchar(c - 32);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
