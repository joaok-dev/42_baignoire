#include "../includes/ft.h"

/**
 * @brief Opens a file for reading.
 * This function attempts to open a file with read-only permissions. If the file
 * cannot be opened, it prints an error message and the system error.
 *
 * @param filename The name of the file to be opened.
 *
 * @return int The file descriptor if the file is successfully opened, or -1 if an
 *             error occurs.
 *
 * Flow:
 * 1. Attempt to open the file in read-only mode.
 * 2. If the file cannot be opened:
 *    a. Print a custom error message indicating the file open error.
 *    b. Print the system error message.
 * 3. Return the file descriptor or -1 if an error occurred.
 */
int	ft_open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(ERROR_FILE_OPEN);
		ft_print_system_error();
	}
	return (fd);
}

/**
 * @brief Closes an open file descriptor.
 * This function attempts to close an open file descriptor. If the file cannot be
 * closed, it prints an error message and the system error.
 *
 * @param fd The file descriptor to be closed.
 *
 * Flow:
 * 1. Attempt to close the file descriptor.
 * 2. If the file descriptor cannot be closed:
 *    a. Print a custom error message indicating the file close error.
 *    b. Print the system error message.
 */
void	ft_close_file(int fd)
{
	if (close(fd) == -1)
	{
		ft_print_error(ERROR_FILE_CLOSE);
		ft_print_system_error();
	}
}

/**
 * @brief Reads data from a file descriptor.
 * This function attempts to read a specified number of bytes from a file
 * descriptor into a buffer. If the read operation fails, it prints an error message
 * and the system error.
 *
 * @param fd The file descriptor to read from.
 * @param buf The buffer to store the read data.
 * @param count The number of bytes to read.
 *
 * @return ssize_t The number of bytes read, or -1 if an error occurs.
 *
 * Flow:
 * 1. Attempt to read the specified number of bytes from the file descriptor into
 *    the buffer.
 * 2. If the read operation fails:
 *    a. Print a custom error message indicating the file read error.
 *    b. Print the system error message.
 * 3. Return the number of bytes read, or -1 if an error occurred.
 */
ssize_t	ft_read_file(int fd, void *buf, size_t count)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buf, count);
	if (bytes_read == -1)
	{
		ft_print_error(ERROR_FILE_READ);
		ft_print_system_error();
	}
	return (bytes_read);
}
