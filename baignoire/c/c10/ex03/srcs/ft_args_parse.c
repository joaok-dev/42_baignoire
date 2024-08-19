#include "../includes/ft.h"

/**
 * @brief Checks if the argument is the "-C" option.
 * This function compares the given argument to the string "-C". If they match,
 * it sets the `use_c_option` flag in the `hexdump` structure and returns 1.
 * Otherwise, it returns 0.
 *
 * @param arg The command line argument to check.
 * @param hexdump Pointer to the t_hexdump structure where options are stored.
 *
 * @return int 1 if the argument is "-C", otherwise 0.
 *
 * Flow:
 * 1. Compare the argument `arg` with the string "-C".
 * 2. If they are equal, set `hexdump->use_c_option` to 1 and return 1.
 * 3. If they are not equal, return 0.
 */
static int	check_c_option(const char *arg, t_hexdump *hexdump)
{
	if (ft_strcmp(arg, "-C") == 0)
	{
		hexdump->use_c_option = 1;
		return (1);
	}
	return (0);
}

/**
 * @brief Initializes the t_hexdump structure.
 * This function initializes the members of the `hexdump` structure with
 * default values.
 * It sets the file descriptor to -1, `use_c_option` to 0, assigns the
 * program name, and sets the total bytes counter to 0.
 *
 * @param hexdump Pointer to the t_hexdump structure to initialize.
 * @param program_name The name of the program, typically argv[0].
 *
 * Flow:
 * 1. Set `hexdump->fd` to -1.
 * 2. Set `hexdump->use_c_option` to 0.
 * 3. Set `hexdump->program_name` using the basename of `program_name`.
 * 4. Set `hexdump->total_bytes` to 0.
 */
static void	init_hexdump(t_hexdump *hexdump, char *program_name)
{
	hexdump->fd = -1;
	hexdump->use_c_option = 0;
	hexdump->program_name = basename(program_name);
	hexdump->total_bytes = 0;
}

/**
 * @brief Parses command-line arguments for the hexdump utility.

	* This function processes command-line arguments to configure the hexdump utility's
 * behavior, including handling options and file names.
 *
 * @param argc The count of command-line arguments.
 * @param argv The array of command-line argument strings.
 * @param hexdump A pointer to the t_hexdump structure to store parsed data.
 *
 * @return int 1 if the parsing is successful and the file is opened,
	0 otherwise.
 *
 * Flow:
 * 1. If the number of arguments is less than 2,
	print an error message and return 0.
 * 2. Initialize the hexdump structure using init_hexdump.
 * 3. Iterate through the arguments starting from index 1:
 *    a. If the argument starts with '-', check the option using check_c_option.
 *    b. If the option is invalid, print an error message and return 0.
 * 4. If all arguments are options,
	set the file descriptor to standard input (0).
 * 5. If there are non-option arguments,
	open the file specified by the first non-option argument.
 * 6. Return 1 if the file descriptor is valid, 0 otherwise.
 */
int	ft_parse_arguments(int argc, char **argv, t_hexdump *hexdump)
{
	int	i;

	if (argc < 2)
	{
		ft_print_error(ERROR_ARGS);
		return (0);
	}
	init_hexdump(hexdump, argv[0]);
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (!check_c_option(argv[i], hexdump))
		{
			ft_print_error(ERROR_ARGS);
			return (0);
		}
		i++;
	}
	if (i == argc)
		hexdump->fd = 0;
	else
		hexdump->fd = ft_open_file(argv[i]);
	return (hexdump->fd != -1);
}
