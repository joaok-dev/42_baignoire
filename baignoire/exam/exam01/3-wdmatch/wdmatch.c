#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
 * Checks if all characters of the first string (str1) appear
 * in the second string (str2) in the same order.
 * It iterates through str1 and for each character in str1,
 * it moves through str2 until it finds a matching character.
 * If a character from str1 is not found in str2, it returns 0.
 * If all characters of str1 are found in str2 in the correct order,
 * it returns 1.
 */
int	ft_wdmatch(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 == *str2)
			str1++;
		str2++;
	}
	return (*str1 == '\0');
}

int	main(int argc, char **argv)
{
	char	*first_str;
	char	*second_str;

	if (argc == 3)
	{
		first_str = argv[1];
		second_str = argv[2];
		if (ft_wdmatch(first_str, second_str))
		{
			while (*first_str)
				ft_putchar(*first_str++);
		}
	}
	ft_putchar('\n');
	return (0);
}
