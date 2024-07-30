#include <unistd.h>
#include "ft_stock_str.h"

/*
 * ft_putchar - Writes a single character to standard output
 *
 * This function uses the write system call to output a single character.
 *
 * @c: The character to be written
 *
 * Flow:
 * 1. Use write to output the character to file descriptor 1 (stdout)
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
 * ft_putstr - Writes a string to standard output
 *
 * This function iterates through the input string, writing each
 * character to stdout until it reaches the null terminator.
 *
 * @str: The string to be written
 *
 * Flow:
 * 1. Iterate through each character in the string
 * 2. Write each character to stdout
 * 3. Continue until null terminator is reached
 */
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

/*
 * ft_putnbr - Writes an integer to standard output
 *
 * This function handles the conversion of an integer to its string
 * representation and writes it to stdout, including negative numbers
 * and the special case of INT_MIN.
 *
 * @nb: The integer to be written
 *
 * Flow:
 * 1. Handle special case of INT_MIN
 * 2. Handle negative numbers
 * 3. Recursively break down number into digits
 * 4. Write each digit as a character
 */
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

/*
 * ft_show_tab - Displays the content of an array of s_stock_str structures
 *
 * This function iterates through an array of s_stock_str structures,
 * printing the str, size, and copy members of each structure.
 *
 * @par: Pointer to the array of s_stock_str structures
 *
 * Flow:
 * 1. Iterate through the array until a structure with str == NULL is found
 * 2. For each structure:
 *    a. Print str followed by a newline
 *    b. Print size followed by a newline
 *    c. Print copy followed by a newline
 */
void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != NULL)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_putstr(par->copy);
		ft_putchar('\n');
		par++;
	}
}
