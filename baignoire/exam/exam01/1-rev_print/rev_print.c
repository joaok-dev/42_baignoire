#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strelen(char *str)
{
	char	*s;

	s = str;
	while (*str)
		str++;
	return (str - s);
}

void	ft_swap_chars(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_rev_print (char *str)
{
	char	*left;
	char	*right;

	left = str;
	right = str + ft_strelen(str) - 1;
	while (left < right)
	{
		ft_swap_chars(left, right);
		left++;
		right--;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*error;

	error = "Error: One and only one parameter is required.";
	if (argc != 2)
	{
		ft_putstr(error);
		ft_putchar('\n');
		return (1);
	}
	ft_rev_print(argv[1]);
	ft_putstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
