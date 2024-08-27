#include <unistd.h>

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

static void	ft_print_union(char *s1, char *s2)
{
	char	*start;

	start = s1;
	while (*s1)
	{
		if (!ft_is_duplicate(start, s1, *s1))
			write(1, s1, 1);
		s1++;
	}
	start = s1;
	while (*s2)
	{
		if (!ft_is_duplicate(s1, s2, *s2))
			write(1, s2, 1);
		s2++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_print_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
