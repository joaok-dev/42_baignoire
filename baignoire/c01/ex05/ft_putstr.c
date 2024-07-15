#include <unistd.h>

void		ft_putstr(char *str);

int	main(void)
{
	ft_putstr("Joao Kennedy");
}

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
}
