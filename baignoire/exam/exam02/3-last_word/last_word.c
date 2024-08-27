#include <unistd.h>

int	ft_is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

void	ft_last_word(char *str)
{
	char	*end;

	end = str;
	while (*end)
		end++;
	while (end > str && ft_is_delimiter(*(end - 1)))
		end--;
	while (end > str && !ft_is_delimiter(*(end - 1)))
		end--;
	while (*end && !ft_is_delimiter(*end))
	{
		write(1, end, 1);
		end++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
