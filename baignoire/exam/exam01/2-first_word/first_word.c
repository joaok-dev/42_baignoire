#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_first_word(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str && *str != ' ' && *str != '\t')
	{
		ft_putchar(*str);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	ft_first_word(argv[1]);
	ft_putchar('\n');
	return (0);
}
