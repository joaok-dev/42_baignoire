#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_check_string(char *str)
{
	while (*str)
	{
		if (*str == 'a')
		{
			ft_putstr("a\n");
			return ;
		}
		str++;
	}
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr("a\n");
	else
		ft_check_string(argv[1]);
	return (0);
}
