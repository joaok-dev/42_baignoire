#include "../includes/ft.h"

/**
 * @brief Processes and prints the last part of a buffer.
 *
 * This function takes a buffer and prints the last 'byte_count' bytes from it.
 * If the buffer is smaller than 'byte_count', it prints the entire buffer.
 *
 * @param buffer The buffer containing data to be processed.
 * @param buffer_size The size of the buffer.
 * @param byte_count The number of bytes from the end of the buffer to
 * be printed.
 * @return Always returns 1 (success).
 *
 * Flow:
 * 1. Determine the starting point from which to print the buffer.
 * 2. If the buffer size is less than or equal to byte_count, start from
 * the beginning.
 * 3. Otherwise, start from (buffer_size - byte_count).
 * 4. Use a pointer to traverse from the start position to the end
 * of the buffer.
 * 5. Print each character using the ft_putchar function.
 */
int ft_process_buffer(char *buffer, size_t buffer_size, size_t byte_count)
{
	size_t	start;
	char	*ptr;

	if (buffer_size <= byte_count)
		start = 0;
	else
		start = buffer_size - byte_count;
	ptr = buffer + start;
	while (ptr < buffer + buffer_size)
	{
		ft_putchar(*ptr);
		ptr++;
	}
	return (1);
}


/**
 * @brief Processes the last part of a file based on byte or line mode.
 *
 * This function determines whether to process the file by bytes or by
 * lines based on 'is_byte_mode'.
 * It delegates the task to either ft_tail_file_bytes or ft_tail_file_lines.
 *
 * @param fd The file descriptor of the file to be processed.
 * @param count The number of bytes or lines to be processed.
 * @param is_byte_mode Flag indicating whether to process by bytes (1)
 * or lines (0).
 * @return Returns 1 on success, 0 on failure.
 */
int ft_tail_file(int fd, size_t count, int is_byte_mode)
{
    if (is_byte_mode)
    {
        return ft_tail_file_bytes(fd, count);
    }
    else
    {
        return ft_tail_file_lines(fd, count);
    }
}

/**
 * @brief Reads bytes from a file and stores them in a circular buffer.
 *
 * This function reads data from the file descriptor 'fd' into a temporary
 * buffer and then stores
 * the last 'byte_count' bytes in a circular buffer.
 *
 * @param fd The file descriptor from which to read.
 * @param circular_buffer The circular buffer to store the bytes.
 * @param byte_count The number of bytes to be stored in the circular buffer.
 * @return The total number of bytes stored, or (size_t)-1 if a read error
 * occurs.
 *
 * Flow:
 * 1. Initialize 'total_bytes' to 0 to track the total bytes stored.
 * 2. Read data from the file into a temporary buffer in chunks of
 * size BUFFER_SIZE.
 * 3. If the total bytes read so far plus the new bytes read is less than or
 * equal to 'byte_count':
 *    - Copy the new bytes into the circular buffer.
 *    - Update 'total_bytes'.
 * 4. If the total bytes read so far plus the new bytes read exceeds
 * 'byte_count':
 *    - Copy the remaining bytes that fit into the circular buffer.
 *    - Wrap around and copy the rest to the beginning of the circular buffer.
 *    - Set 'total_bytes' to 'byte_count'.
 * 5. If a read error occurs, return (size_t)-1.
 * 6. Return the total number of bytes stored.
 */
size_t	ft_read_and_store_bytes(int fd, char *circular_buffer, size_t byte_count)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	size_t	total_bytes;
	size_t	remaining;

	total_bytes = 0;
	bytes_read = ft_read_file(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (total_bytes + bytes_read <= byte_count)
		{
			ft_memcpy(circular_buffer + total_bytes, buffer, bytes_read);
			total_bytes += bytes_read;
		}
		else
		{
			remaining = byte_count - total_bytes;
			ft_memcpy(circular_buffer + total_bytes, buffer, remaining);
			ft_memcpy(circular_buffer, buffer + remaining, bytes_read - remaining);
			total_bytes = byte_count;
		}
	}
	if (bytes_read == -1)
		return ((size_t)-1);
	return (total_bytes);
}

/**
 * @brief Initializes a circular buffer for storing bytes.
 *
 * This function allocates memory for a circular buffer of size 'byte_count'.
 * If memory allocation fails, it prints an error message.
 *
 * @param byte_count The size of the circular buffer to be allocated.
 * @return A pointer to the allocated circular buffer, or NULL if
 * allocation fails.
 */
char	*ft_init_circular_buffer(size_t byte_count)
{
    char	*circular_buffer;

	circular_buffer = malloc(byte_count);
	if (!circular_buffer)
		ft_print_error(ERROR_MEMORY);
	return (circular_buffer);
}
/**
 * @brief Processes and prints the last 'byte_count' bytes of a file.
 *
 * This function reads the file in chunks, storing the last 'byte_count' bytes
 * in a circular buffer,
 * and then prints those bytes.
 *
 * @param fd The file descriptor of the file to be processed.
 * @param byte_count The number of bytes from the end of the file to be printed.
 * @return Returns 1 on success, 0 on failure.
 *
 * Flow:
 * 1. Initialize the circular buffer using ft_init_circular_buffer.
 * 2. If the circular buffer allocation fails, return 0.
 * 3. Read data from the file and store the last 'byte_count' bytes in the
 * circular buffer using ft_read_and_store_bytes.
 * 4. If a read error occurs, free the circular buffer and return 0.
 * 5. Output the stored bytes from the circular buffer using ft_output_bytes.
 * 6. Free the circular buffer and return the result of the output operation.
 */
int	ft_tail_file_bytes(int fd, size_t byte_count)
{
	char	*circular_buffer;
	size_t	total_bytes;
	int		result;

	circular_buffer = ft_init_circular_buffer(byte_count);
	if (!circular_buffer)
		return (0);
	total_bytes = ft_read_and_store_bytes(fd, circular_buffer, byte_count);
	if (total_bytes == (size_t)-1)
	{
		free(circular_buffer);
		return (0);
	}
	result = ft_output_bytes(circular_buffer, total_bytes, byte_count);
	free(circular_buffer);
	return (result);
}

/**
 * @brief Processes and prints the last 'line_count' lines of a file.
 *
 * This function reads the file line by line, storing the last 'line_count'
 * lines in a circular buffer,
 * and then prints those lines.
 *
 * @param fd The file descriptor of the file to be processed.
 * @param line_count The number of lines from the end of the file
 * to be printed.
 * @return Returns 1 on success, 0 on failure.
 *
 * Flow:
 * 1. Use ft_store_last_lines to read and store the last 'line_count' lines
 * in an array of strings.
 * 2. If the line array is NULL, return 0.
 * 3. Print the stored lines in the correct order, handling any wrap-around
 * in the circular buffer.
 * 4. Free the allocated memory for each line and the line array itself.
 * 5. Return 1.
 */
int ft_tail_file_lines(int fd, size_t line_count)
{
	char	**lines;
	size_t	i;
	size_t	start;

	lines = ft_store_last_lines(fd, line_count);
	if (!lines)
		return (0);

	i = 0;
	while (i < line_count && !lines[i])
		i++;
	start = i;
	while (i < line_count)
	{
		if (lines[i])
		{
			ft_putstr(lines[i]);
			ft_putchar('\n');
			free(lines[i]);
		}
		i++;
	}
	i = 0;
	while (i < start)
	{
		if (lines[i])
		{
			ft_putstr(lines[i]);
			ft_putchar('\n');
			free(lines[i]);
		}
		i++;
	}
	free(lines);
	return (1);
}

/**
 * @brief Processes the last part of the standard input based on byte
 * or line mode.
 *
 * This function is a wrapper around ft_tail_file and processes standard
 * input (file descriptor 0).
 *
 * @param count The number of bytes or lines to be processed.
 * @param is_byte_mode Flag indicating whether to process by bytes (1)
 * or lines (0).
 * @return Returns 1 on success, 0 on failure.
 */
int	ft_tail_stdin(size_t count, int is_byte_mode)
{
	return ft_tail_file(0, count, is_byte_mode);
}

/**
 * @brief Outputs the stored bytes from a circular buffer.
 *
 * This function writes the last 'byte_count' bytes from the circular buffer
 * to the standard output.
 *
 * @param circular_buffer The circular buffer containing the bytes to be output.
 * @param total_bytes The total number of bytes stored in the circular buffer.
 * @param byte_count The number of bytes to be output.
 * @return Returns 1 on success, 0 on failure.
 *
 * Flow:
 * 1. Calculate the starting point in the circular buffer based on 'total_bytes'
 * and 'byte_count'.
 * 2. Write the bytes from the circular buffer starting from the calculated
 * point to the standard output.
 * 3. If the write operation fails, return 0.
 * 4. Return 1 on successful output.
 */
int	ft_output_bytes(char *circular_buffer, size_t total_bytes, size_t byte_count)
{
	size_t	start;

	start = 0;
	if (total_bytes > byte_count)
		start = total_bytes - byte_count;
	if (write(1, circular_buffer + start, total_bytes - start) == -1)
		return (0);
	return (1);
}

/**
 * @brief Stores the last n lines read from a file descriptor.
 *
 * This function reads data from the file descriptor 'fd' and stores the last
 * 'n_lines' lines
 * in a dynamically allocated array of strings. It uses a circular buffer
 * approach to keep only the last 'n_lines' lines.
 *
 * @param fd The file descriptor from which to read.
 * @param n_lines The number of last lines to be stored.
 * @return A pointer to an array of strings containing the last 'n_lines'
 * lines, or NULL if an error occurs.
 *
 * Flow:
 * 1. Allocate memory for the array of strings to store the lines.
 * 2. Initialize 'current_line' to keep track of the current line number.
 * 3. Read data from the file descriptor into a buffer in chunks of
 * size BUFFER_SIZE.
 * 4. For each chunk:
 *    - Initialize 'line_start' to the beginning of the buffer.
 *    - Iterate through the buffer to find newline characters.
 *    - When a newline is found, null-terminate the line and duplicate it.
 *    - Store the duplicated line in the 'lines' array, freeing the old line
 *    if necessary.
 *    - Increment 'current_line' and update 'line_start' to the character
 *    after the newline.
 * 5. Handle read errors by printing an error message and returning NULL.
 * 6. Return the array of strings containing the last 'n_lines' lines.
 */
char	**ft_store_last_lines(int fd, size_t n_lines)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	char	**lines;
	size_t	current_line;
	char	*line_start;
	char	*ptr;

	lines = (char **)malloc(sizeof(char *) * n_lines);
	if (!lines)
		return (NULL);
	current_line = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		line_start = buffer;
		ptr = buffer;
		while (ptr < buffer + bytes_read)
		{
			if (*ptr == '\n')
			{
				*ptr = '\0';
				if (current_line < n_lines)
					lines[current_line] = ft_strdup(line_start);
				else
				{
					free(lines[current_line % n_lines]);
					lines[current_line % n_lines] = ft_strdup(line_start);
				}
				current_line++;
				line_start = ptr + 1;
			}
			ptr++;
		}
	}
	if (bytes_read == -1)
	{
		ft_print_error(ERROR_FILE_READ);
		ft_print_system_error();
		return (NULL);
	}
	return (lines);
}
