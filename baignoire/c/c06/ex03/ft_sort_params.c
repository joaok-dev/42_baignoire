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

int	ft_strcmp(char *s1, char *s2)
{
	char	*str1;
	char	*str2;

	str1 = s1;
	str2 = s2;
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	ft_argv_sort_insertion(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*key;

	i = 2;
	while (i < argc)
	{
		key = argv[i];
		j = i - 1;
		while (j > 0 && ft_strcmp(argv[j], key) > 0)
		{
			argv[j + 1] = argv[j];
			j--;
		}
		argv[j + 1] = key;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*error;
	int		i;

	error = "Error: Addtional arguments required.\n";
	if (argc <= 1)
	{
		ft_putstr(error);
		return (1);
	}
	ft_argv_sort_insertion(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
