#include "../includes/ft.h"

/*
 * main - Entry point of the program
 *
 * This function processes command-line arguments and handles file operations.
 * It can process multiple files or read from stdin if no files are specified.
 *
 * @argc: The number of command-line arguments
 * @argv: The array of command-line argument strings
 *
 * Return: 0 on success, 1 if any file operation failed
 *
 * Flow:
 * 1. Validate command-line arguments
 * 2. If no files specified, process stdin
 * 3. Otherwise, iterate through each filename argument:
 *    a. Handle each file
 *    b. If any file operation fails, set result to 1
 * 4. Return the final result
 */
int	main(int argc, char **argv)
{
	char	**arg_ptr;
	int		result;

	if (ft_validate_args(argc, argv))
		return (1);
	if (argc == 1)
		return (ft_read_and_write(0, "stdin"));
	arg_ptr = argv + 1;
	result = 0;
	while (*arg_ptr)
	{
		if (ft_handle_file(*arg_ptr))
			result = 1;
		arg_ptr++;
	}
	return (result);
}
