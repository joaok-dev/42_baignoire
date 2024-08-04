#include "../includes/ft.h"

/*
 * ft_handle_file - Opens and processes a file or handles stdin
 *
 * This function opens the specified file (or uses stdin if filename is "-"),
 * reads its contents, and writes them to stdout.
 *
 * @filename: The name of the file to process or "-" for stdin
 *
 * Return: 0 on success, 1 on error
 *
 * Flow:
 * 1. If filename is "-", process stdin
 * 2. Otherwise, open the file
 * 3. If file open fails, display error and return 1
 * 4. Read and write file contents
 * 5. Close the file
 * 6. Return the result of read_and_write operation
 */
int	ft_handle_file(char *filename)
{
	int	fd;
	int	result;

	if (*filename == '-' && *(filename + 1) == '\0')
		return (ft_read_and_write(0, "stdin"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_display_error(filename);
		return (1);
	}
	result = ft_read_and_write(fd, filename);
	close(fd);
	return (result);
}
