#include <unistd.h>

static void	ft_first_word(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str && *str != ' ' && *str != '\t')
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_first_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
