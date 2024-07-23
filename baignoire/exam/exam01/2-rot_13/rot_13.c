#include <unistd.h>

// Function to write a single character
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Function to write a string
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

// Function to apply ROT13 transformation
char	*ft_rot13(char *str)
{
	char	*new_str;

	new_str = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = ((*str - 'A' + 13) % 26) + 'A';
		else if (*str >= 'a' && *str <= 'z')
			*str = ((*str - 'a' + 13) % 26) + 'a';
		str++;
	}
	return (new_str);
}

// Main function to handle arguments and output
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	ft_putstr(ft_rot13(argv[1]));
	ft_putchar('\n');
	return (0);
}
