#include <unistd.h>

/*
 * ft_putstr - Writes a string to standard output
 *
 * This function iterates through the input string, writing each
 * character to stdout until it reaches the null terminator.
 *
 * @str: The null-terminated string to be written
 *
 * Flow:
 * 1. While the current character is not null:
 *    a. Write the current character to stdout (fd 1)
 *    b. Move to the next character
 * 2. Stop when the null terminator is reached
 */
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
