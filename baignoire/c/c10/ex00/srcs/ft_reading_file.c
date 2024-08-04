#include "../includes/ft.h"

/*
 * ft_reading_file - Reads the contents of a file and prints it
 *
 * @file: The name of the file to read
 * @buffer: The buffer to store the file contents
 *
 * Return: 0 on success, 1 on failure
 *
 * Flow:
 * 1. Open the file
 * 2. Read the file contents into the buffer
 * 3. Print the buffer contents
 * 4. Close the file
 */
int	ft_reading_file(char *file, char *buffer)
{
	int		fd;
	ssize_t	elements_read;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(ERR_READ);
		return (1);
	}
	elements_read = read(fd, buffer, (BUFFER_SIZE - 1));
	if (elements_read == -1)
	{
		ft_putstr(ERR_READ);
		close(fd);
		return (1);
	}
	buffer[elements_read] = '\0';
	ft_putstr(buffer);
	close(fd);
	return (0);
}
