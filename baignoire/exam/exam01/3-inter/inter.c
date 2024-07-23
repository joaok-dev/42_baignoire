#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Check if a char is present in the string
int	ft_strchar(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

// Check if a char has been encountered before in a range of string
int	ft_check_prev(char *start, char *end, char c)
{
	while (start < end)
	{
		if (*start == c)
			return (1);
		start++;
	}
	return (0);
}

// Find and print the instersection of two string without duplicates
void	ft_inter(char *str1, char *str2)
{
	char	*current_char;

	current_char = str1;
	while (*current_char)
	{
		if (ft_strchar(str2, *current_char)
			&& !ft_check_prev(str1, current_char, *current_char))
			ft_putchar(*current_char);
		current_char++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
