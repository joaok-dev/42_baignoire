#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	char	str1[] = "Hello, World!";
	char	str2[] = "42";

	ft_putstr(str1);
	write(1, "\n", 1);
	ft_putstr(str2);
	write(1, "\n", 1);
	return (0);
}
