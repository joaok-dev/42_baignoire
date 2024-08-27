#include <unistd.h>

static int	ft_is_in_string(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static int	ft_is_duplicate(char *start, char *current, char c)
{
	while (start < current)
	{
		if (*start == c)
			return (1);
		start++;
	}
	return (0);
}

static void	ft_print_inter(char *s1, char *s2)
{
	char	*start;

	start = s1;
	while (*s1)
	{
		if (ft_is_in_string(s2, *s1) && !ft_is_duplicate(start, s1, *s1))
			write(1, s1, 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_print_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
