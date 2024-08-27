#include <unistd.h>

int	ft_is_char_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	ft_inter(char *s1, char *s2)
{
	char	used[256] = {0};

	while (*s1)
	{
		if (!used[(unsigned char)*s1] && ft_is_char_in_string(*s1, s2))
		{
			write(1, s1, 1);
			used[(unsigned char)*s1] = 1;
		}
		s1++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	else
		write(1, "\n", 1);
	return (0);
}
