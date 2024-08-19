#include "../includes/ft.h"

/**
 * @brief Writes a single character to standard output.
 * This function writes a single character to the standard output.
 *
 * @param c The character to be written.
 *
 * Flow:
 * 1. Use the write system call to output the character.
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * @brief Writes a string to standard output.
 * This function writes each character of the given string to the standard output.
 *
 * @param str The string to be written.
 *
 * Flow:
 * 1. Initialize a pointer to the start of the string.
 * 2. Iterate through each character in the string:
 *    a. Write the current character to standard output using ft_putchar.
 *    b. Move to the next character.
 */
void	ft_putstr(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		ft_putchar(*ptr);
		ptr++;
	}
}

/**
 * @brief Prints a formatted file header to standard output.
 * This function prints a formatted header with the file name, typically used to
 * indicate the beginning of a file's contents.
 *
 * @param filename The name of the file to be displayed in the header.
 *
 * Flow:
 * 1. Print the opening part of the header ("\n==> ").
 * 2. Print the file name.
 * 3. Print the closing part of the header (" <==\n").
 */
void	ft_print_file_header(const char *filename)
{
	ft_putstr("\n==> ");
	ft_putstr(filename);
	ft_putstr(" <==\n");
}
