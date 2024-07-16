#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	char	*name;
	char	*error;

	error = "Error: no additional parameters allowrd.\n";
	if (argc > 1)
	{
		ft_putstr(error);
		return (1);
	}
	name = argv[0];
	ft_putstr(name);
	ft_putchar('\n');
	return (0);
}
