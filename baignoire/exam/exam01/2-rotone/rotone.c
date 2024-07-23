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

char	*ft_ratone(char *str)
{
	char	*new_str;

	new_str = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = ((*str - 'A' + 1) % 26) + 'A';
		else if (*str >= 'a' && *str <= 'z')
			*str = ((*str - 'a' + 1) % 26) + 'a';
		str++;
	}
	return (new_str);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	ft_putstr(ft_ratone(argv[1]));
	ft_putchar('\n');
	return (0);
}
