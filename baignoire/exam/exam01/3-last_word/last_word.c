#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* ft_last_word: Finds and prints the last word in a string.
 * 1. Locates the end of the string.
 * 2. Moves backwards, skipping trailing spaces and tabs.
 * 3. Identifies the start of the last word.
 * 4. Prints the last word character by character.
 * Note: Handles edge cases like strings with only spaces/tabs.
 */
void	ft_last_word(char *str)
{
	char	*end;
	char	*current;

	end = str;
	while (*end)
		end++;
	end--;
	while (end >= str && (*end == ' ' || *end == '\t'))
		end--;
	current = end;
	while (current >= str && *current != ' ' && *current != '\t')
		current--;
	current++;
	while (current <= end)
	{
		ft_putchar(*current);
		current++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_last_word(argv[1]);
	ft_putchar('\n');
	return (0);
}
