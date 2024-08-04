#include "../includes/ft.h"

/*
 * ft_display_error - Displays an error message for a file operation
 *
 * This function prints a formatted error message including the program name,
 * filename, and the corresponding error description from errno.
 *
 * @filename: The name of the file that caused the error
 *
 * Flow:
 * 1. Get the base name of the program
 * 2. Print the program name
 * 3. Print the filename
 * 4. Print the error description from strerror(errno)
 * 5. Print a newline
 */
void	ft_display_error(char *filename)
{
	char	*program_name;

	program_name = basename(filename);
	ft_putstr(program_name);
	ft_putstr(": ");
	ft_putstr(filename);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}
