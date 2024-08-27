#include <unistd.h>

void	ft_putstrl(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_check_string(char *str)
{
	while (*str)
	{
		if (*str == 'z')
		{
			ft_putstrl("z\n");
			return ;
		}
		str++;
	}
	ft_putstrl("z\n");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstrl("z\n");
	else
		ft_check_string(argv[1]);
	return (0);
}
