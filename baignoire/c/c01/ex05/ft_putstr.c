#include <unistd.h>

void		ft_putstr(char *str);

int	main(void)
{
	ft_putstr("Joao Kennedy");
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
