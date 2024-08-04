#include "../includes/ft.h"

/*
 * ft_read_and_write - Reads from a file descriptor and writes to stdout
 *
 * This function reads data from the given file descriptor in chunks and
 * writes it to the standard output. It handles read errors and EOF.
 *
 * @fd: The file descriptor to read from
 * @filename: The name of the file (for error reporting)
 *
 * Return: 0 on success, 1 on read error
 *
 * Flow:
 * 1. Read data from fd into buffer
 * 2. If read error occurs, display error and return 1
 * 3. If EOF reached (bytes_read == 0), break the loop
 * 4. Write the read data to stdout character by character
 * 5. Repeat until EOF or error
 */
int	ft_read_and_write(int fd, char *filename)
{
	char	buffer[BUFFER_SIZE];
	char	*ptr;
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_display_error(filename);
			return (1);
		}
		if (bytes_read == 0)
			break ;
		ptr = buffer;
		while (bytes_read--)
			ft_putchar(*ptr++);
	}
	return (0);
}
