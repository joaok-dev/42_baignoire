#include "../includes/ft.h"

/*
 * ft_putchar - Writes a single character to standard output
 *
 * This function uses the write system call to output a single character
 * to the standard output (file descriptor 1).
 *
 * @c: The character to be written
 *
 * Flow:
 * 1. Use write system call to output the character
 * 2. Write 1 byte to file descriptor 1 (stdout)
 * 3. The address of c is passed to write, which outputs its value
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
