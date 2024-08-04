#include "../includes/ft.h"

/*
 * ft_validate_args - Validates the command-line arguments
 *
 * This function checks if the program was called with valid arguments.
 *
 * @argc: The number of command-line arguments
 * @argv: The array of command-line argument strings
 *
 * Return: 0 if arguments are valid, 1 otherwise
 *
 * Flow:
 * 1. Check if argc is less than 1 or argv is NULL
 * 2. If invalid, print error message and return 1
 * 3. Otherwise, return 0 (arguments are valid)
 */
int	ft_validate_args(int argc, char **argv)
{
	if (argc < 1 || !argv)
	{
		ft_putstr(ERR_ARGS);
		return (1);
	}
	return (0);
}
