#include <unistd.h>

static void	ft_wdmatch(char *s1, char *s2)
{
	while (*s2 && *s1)
	{
		if (*s1 == *s2)
			s1++;
		s2++;
	}
	if (*s1 == '\0')
		while (*s1--)
			write(1, s1, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
