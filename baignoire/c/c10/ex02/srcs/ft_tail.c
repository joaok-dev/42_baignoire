#include "../includes/ft.h"

/**
 * @brief Main function for tail-like program.
 *
 * This function is the entry point of the program. It processes command-line arguments,
 * reads data from either standard input or specified files, and prints the last part of the input.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return Returns 0 on success, 1 on failure.
 *
 * Flow:
 * 1. Initialize a t_tail_data structure to hold parsed argument data.
 * 2. Parse command-line arguments using ft_parse_args. If parsing fails, return 1.
 * 3. If no files are specified, call ft_tail_stdin to process standard input.
 * 4. If files are specified, iterate over each file:
 *    - Open the file using ft_open_file.
 *    - If the file is successfully opened:
 *      - Print the file header if multiple files are specified.
 *      - Call ft_tail_file to process the file.
 *      - Close the file using ft_close_file.
 *    - If processing any file fails, return 1.
 * 5. Return 0 upon successful completion.
 */
int	main(int argc, char **argv)
{
	t_tail_data	data;
	int			i;
	int			fd;

	if (!ft_parse_args(argc, argv, &data))
		return (1);
	if (data.file_count == 0)
	{
		if (!ft_tail_stdin(data.count, data.is_byte_mode))
			return (1);
	}
	else
	{
		i = 0;
		while (i < data.file_count)
		{
			fd = ft_open_file(data.filenames[i]);
			if (fd != -1)
			{
				if (data.file_count > 1)
					ft_print_file_header(data.filenames[i]);
				if (!ft_tail_file(fd, data.count, data.is_byte_mode))
				{
					ft_close_file(fd);
					return (1);
				}
				ft_close_file(fd);
			}
			i++;
		}
	}
	return(0);
}
