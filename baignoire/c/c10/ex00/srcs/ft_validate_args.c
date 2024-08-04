#include "../includes/ft.h"

/*
 * ft_validate_args - Validates the number of command-line arguments
 *
 * This function checks if the number of arguments passed to the program
 * is exactly 2 (program name + 1 argument). It prints an error message
 * if the number of arguments is incorrect.
 *
 * @argc: The number of command-line arguments
 *
 * Return: 0 if the number of arguments is correct, 1 otherwise
 *
 * Flow:
 * 1. If argc is less than 2 (no file argument):
 *    a. Print "File name missing." error
 *    b. Return 1 (error)
 * 2. If argc is greater than 2 (too many arguments):
 *    a. Print "Too many arguments." error
 *    b. Return 1 (error)
 * 3. If argc is exactly 2:
 *    a. Return 0 (success)
 */
int	ft_validate_args(int argc)
{
	if (argc < 2)
	{
		ft_putstr(ERR_NO_FILE);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr(ERR_ARGS);
		return (1);
	}
	return (0);
}
