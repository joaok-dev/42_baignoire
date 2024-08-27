#include <unistd.h>

void	inter(char *s1, char *s2)
{
	char	*start;
	char	*tmp;
	char	*tmp_s2;

	start = s1;
	while (*s1)
	{
		tmp = start;
		while (tmp < s1 && *tmp != *s1)
			tmp++;
		if (tmp == s1)
		{
			tmp_s2 = s2;
			while (*tmp_s2)
			{
				if (*s1 == *tmp_s2)
				{
					write(1, s1, 1);
					break ;
				}
				tmp_s2++;
			}
		}
		s1++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	else
		write(1, "\n", 1);
	return (0);
}
