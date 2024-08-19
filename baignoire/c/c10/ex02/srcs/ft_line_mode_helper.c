#include "../includes/ft.h"

/**
 * @brief Initializes an array of string pointers to store lines.
 * This function allocates memory for an array of string pointers and initializes
 * each pointer to NULL.
 *
 * @param n_lines The number of lines to store.
 *
 * @return char** A dynamically allocated array of string pointers, or NULL if
 *                allocation fails.
 *
 * Flow:
 * 1. Allocate memory for an array of n_lines string pointers.
 * 2. Initialize each pointer in the array to NULL.
 * 3. Return the initialized array.
 */
static char	**ft_init_lines_array(size_t n_lines)
{
	char	**lines;
	char	**ptr;
	char	**end;

	lines = (char **)malloc(n_lines * sizeof(char *));
	if (!lines)
		return (NULL);
	ptr = lines;
	end = lines + n_lines;
	while (ptr < end)
	{
		*ptr = NULL;
		ptr++;
	}
	return (lines);
}

/**
 * @brief Stores a line in the circular buffer of lines.
 * This function stores a line in the circular buffer, freeing the oldest line
 * if necessary.
 *
 * @param lines The array of stored lines.
 * @param n_lines The number of lines to store.
 * @param line The line to be stored.
 * @param current_line A pointer to the index of the current line being stored.
 *
 * Flow:
 * 1. Calculate the current line's position in the circular buffer.
 * 2. If the current line index is within the n_lines limit, store the line directly.
 * 3. If the current line index exceeds the n_lines limit:
 *    a. Free the memory of the oldest line.
 *    b. Store the new line in the appropriate index using modulo operation.
 * 4. Increment the current line index.
 */
static void	ft_store_line(char **lines, size_t n_lines, char *line, size_t *current_line)
{
	char	**current_line_ptr;

	current_line_ptr = lines + (*current_line % n_lines);
	if (*current_line < n_lines)
		*current_line_ptr = ft_strdup(line);
	else
	{
		free(*current_line_ptr);
		*current_line_ptr = ft_strdup(line);
	}
	(*current_line)++;
}

/**
 * @brief Processes a buffer of read data to extract and store lines.
 * This function processes a buffer of read data, extracts lines separated by
 * newlines, and stores them in the circular buffer of lines.
 *
 * @param lines The array of stored lines.
 * @param n_lines The number of lines to store.
 * @param buffer The buffer of read data.
 * @param bytes_read The number of bytes read into the buffer.
 * @param current_line A pointer to the index of the current line being stored.
 *
 * Flow:
 * 1. Initialize line_start to the beginning of the buffer.
 * 2. Iterate through the buffer:
 *    a. If a newline or end of buffer is found, terminate the line.
 *    b. Store the line in the circular buffer using ft_store_line.
 *    c. Update line_start to the character after the newline.
 */
static void	ft_process_buffer(char **lines, size_t n_lines, char *buffer, ssize_t bytes_read, size_t *current_line)
{
	char	*line_start;
	char	*ptr;
	char	*end;

	line_start = buffer;
	ptr = buffer;
	end = buffer + bytes_read;
	while (ptr < end)
	{
		if (*ptr == '\n' || ptr == end - 1)
		{
			if (*ptr != '\n')
				ptr++;
			*ptr = '\0';
			ft_store_line(lines, n_lines, line_start, current_line);
			line_start = ptr + 1;
		}
		ptr++;
	}
}

/**
 * @brief Stores the last n lines from a file descriptor.
 * This function reads data from a file descriptor and stores the last n lines
 * in a dynamically allocated array of strings.
 *
 * @param fd The file descriptor to read from.
 * @param n_lines The number of lines to store.
 *
 * @return char** A dynamically allocated array of strings containing the last
 *                n lines, or NULL if an error occurs.
 *
 * Flow:
 * 1. Initialize an array of n_lines string pointers using ft_init_lines_array.
 * 2. Initialize the current_line index to 0.
 * 3. Read from the file descriptor into a buffer.
 * 4. Process the buffer to extract and store lines using ft_process_buffer.
 * 5. If a read error occurs, free the allocated memory and return NULL.
 * 6. Return the array of stored lines.
 */
char	**ft_store_last_lines(int fd, size_t n_lines)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	char	**lines;
	size_t	current_line;

	lines = ft_init_lines_array(n_lines);
	if (!lines)
		return(NULL);
	current_line = 0;
	while ((bytes_read = ft_read_file(fd, buffer, BUFFER_SIZE)) > 0)
		ft_process_buffer(lines, n_lines, buffer, bytes_read, &current_line);
	if (bytes_read == -1)
	{
		ft_free_lines(lines, n_lines);
		return (NULL);
	}
	return (lines);
}

/**
 * @brief Prints the stored lines.
 * This function prints each line stored in the array of strings.
 *
 * @param lines The array of stored lines.
 * @param n_lines The number of lines to print.
 *
 * Flow:
 * 1. Calculate the end pointer of the lines array.
 * 2. Iterate through the lines array:
 *    a. If the current line is not NULL, print the line followed by a newline.
 *    b. Move to the next line.
 */
void	ft_print_last_lines(char **lines, size_t n_lines)
{
	char	**end;

	end = lines + n_lines;
	while (lines < end && *lines)
	{
		ft_putstr(*lines);
		ft_putchar('\n');
		lines++;
	}
}

/**
 * @brief Frees the memory allocated for stored lines.
 * This function frees the memory allocated for each line in the array and then
 * frees the array itself.
 *
 * @param lines The array of stored lines.
 * @param n_lines The number of lines to free.
 *
 * Flow:
 * 1. Calculate the end pointer of the lines array.
 * 2. Iterate through the lines array:
 *    a. If the current line is not NULL, free the memory of the line.
 *    b. Move to the next line.
 * 3. Free the array of line pointers.
 */
void	ft_free_lines(char **lines, size_t n_lines)
{
	char	**end;

	end = lines + n_lines;
	while (lines < end && *lines)
	{
		free(*lines);
		lines++;
	}
	free (lines - n_lines);
}
