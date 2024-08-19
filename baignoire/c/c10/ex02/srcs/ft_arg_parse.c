#include "../includes/ft.h"

/**
 * @brief Parses command-line arguments for the tail utility.
 * This function processes command-line arguments to configure the tail
 * utility's behavior, including setting the number of lines or bytes to
 * display and handling file names.
 *
 * @param argc The count of command-line arguments.
 * @param argv The array of command-line argument strings.
 * @param data A pointer to the t_tail_data structure to store parsed data.
 *
 * @return int 1 if the parsing is successful, 0 otherwise.
 *
 * Flow:
 * 1. Initialize the parsing index `i` to 1.
 * 2. Set default values in the `data` structure:
 *    a. `count` to 10.
 *    b. `is_byte_mode` to 0.
 *    c. `file_count` to 0.
 *    d. `filenames` to NULL.
 * 3. If there is only one argument (program name), return 1.
 * 4. Check if the first argument is "-c":
 *    a. If the argument count is less than 4, print an error and return 0.
 *    b. Parse the byte count from the second argument.
 *    c. If the byte count is less than or equal to 0, print an error and
 *    return 0.
 *    d. Set `is_byte_mode` to 1 and update the index `i` to 3.
 * 5. Set `file_count` to the number of remaining arguments.
 * 6. Set `filenames` to point to the list of file names starting from the
 * updated index `i`.
 * 7. Return 1 to indicate successful parsing.
 *
 * Error handling:
 * - If the option "-c" is used with insufficient arguments, print an invalid
 *   option error.
 * - If the byte count specified is invalid (non-positive), print an invalid
 *   byte count error.
 */
int	ft_parse_args(int argc, char **argv, t_tail_data *data)
{
	int	i;

	i = 1;
	data->count = 10;
	data->is_byte_mode = 0;
	data->file_count = 0;
	data->filenames = NULL;
	if (argc == 1)
		return (1);
	if (ft_strcmp(argv[i], "-c") == 0)
	{
		if (argc < 4)
		{
			ft_print_error(ERROR_INVALID_OPTION);
			return (0);
		}
		data->count = ft_atoi(argv[2]);
		if (data->count <= 0)
		{
			ft_print_error(ERROR_INVALID_BYTE_COUNT);
			return (0);
		}
		data->is_byte_mode = 1;
		i = 3;
	}
	data->file_count = argc - i;
	data->filenames = &argv[i];
	return (1);
}
