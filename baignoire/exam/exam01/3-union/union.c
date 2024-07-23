#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

/*
	ft_union processes two strings to print unique characters:
	1. It iterates through the first string (str1), printing each character
	that hasn't appeared before in that string.
	2. It then iterates through the second string (str2),
	printing each character that hasn't appeared before in either str1 or
	the part of str2 already processed.
*/
void	ft_union(char *str1, char *str2)
{
	char	*current_char;

	current_char = str1;
	while (*current_char)
	{
		if (!ft_check_prev(str1, current_char, *current_char))
			ft_putchar(*current_char);
		current_char++;
	}
	current_char = str2;
	while (*current_char)
	{
		if (!ft_check_prev(str1, str1 + (current_char - str2), *current_char)
			&& !ft_check_prev(str2, current_char, *current_char))
			ft_putchar(*current_char);
		current_char++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
