#include "../includes/ft.h"

/**
 * @brief Initializes a circular buffer for storing bytes.
 * This function allocates memory for a circular buffer of the specified size.
 *
 * @param byte_count The size of the circular buffer to be allocated.
 *
 * @return char* Pointer to the allocated circular buffer, or NULL if allocation
 *               fails.
 *
 * Flow:
 * 1. Allocate memory for the circular buffer using the specified byte count.
 * 2. If memory allocation fails, print a memory error message.
 * 3. Return the pointer to the allocated circular buffer.
 *
 * Error handling:
 * - If memory allocation fails, print an error message indicating memory
 *   allocation failure.
 */
char	*ft_init_circular_buffer(size_t byte_count)
{
	char	*circular_buffer;

	circular_buffer = malloc(byte_count);
	if (!circular_buffer)
	{
		ft_print_error(ERROR_MEMORY);
		return (NULL);
	}
	return (circular_buffer);
}

/**
 * @brief Reads bytes from a file and stores them in a circular buffer.
 * This function reads bytes from a file descriptor and stores them in the
 * circular buffer, ensuring the buffer does not exceed the specified byte count.
 *
 * @param fd The file descriptor to read from.
 * @param circular_buffer The circular buffer to store the read bytes.
 * @param byte_count The size of the circular buffer.
 *
 * @return size_t The total number of bytes read and stored, or (size_t)-1 if
 *                an error occurs during reading.
 *
 * Flow:
 * 1. Initialize total_bytes to 0 and buffer_pos to 0.
 * 2. Read from the file descriptor into a temporary buffer in a loop.
 * 3. Update total_bytes with the number of bytes read.
 * 4. If the total bytes read are within the byte_count:
 *    a. Copy bytes to the circular buffer.
 *    b. Update buffer_pos.
 * 5. If the total bytes read exceed byte_count:
 *    a. Calculate the overflow.
 *    b. Calculate the start position for copying.
 *    c. Move existing data in the circular buffer to make space.
 *    d. Copy new data into the buffer.
 * 6. If a read error occurs, return (size_t)-1.
 * 7. Return the total number of bytes read if less than byte_count, otherwise return byte_count.
 */
size_t	ft_read_and_store_bytes(int fd, char *circular_buffer, size_t byte_count)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	size_t	total_bytes;
	size_t	buffer_pos;
	size_t	overflow;
	size_t	start;
	size_t	copy_size;

	total_bytes = 0;
	buffer_pos = 0;
	while ((bytes_read = ft_read_file(fd, buffer, BUFFER_SIZE)) > 0)
	{
		total_bytes += bytes_read;
		if (total_bytes <= byte_count)
		{
			ft_memcpy(circular_buffer + buffer_pos, buffer, bytes_read);
			buffer_pos += bytes_read;
		}
		else
		{
			overflow = total_bytes - byte_count;
			start = overflow;
			if (overflow > (size_t)bytes_read)
				start = bytes_read;
			copy_size = bytes_read - start;
			if (start < (size_t)bytes_read)
			{
				ft_memmove(circular_buffer, circular_buffer + start, byte_count - copy_size);
				ft_memcpy(circular_buffer + byte_count - copy_size, buffer + start, copy_size);
			}
		}
	}
	if (bytes_read == -1)
		return ((size_t)-1);
	if (total_bytes < byte_count)
		return total_bytes;
	return byte_count;
}

/**
 * @brief Outputs bytes from the circular buffer to standard output.
 * This function writes the stored bytes from the circular buffer to standard
 * output, ensuring the correct number of bytes are output.
 *
 * @param circular_buffer The circular buffer containing the bytes to output.
 * @param total_bytes The total number of bytes stored in the circular buffer.
 * @param byte_count The number of bytes to output.
 *
 * @return int 1 if the output is successful, 0 if an error occurs during writing.
 *
 * Flow:
 * 1. Calculate the number of bytes to output.
 * 2. If total_bytes is less than byte_count, set to_output to total_bytes.
 * 3. Write the bytes to standard output.
 * 4. If writing fails, return 0.
 * 5. Add a newline at the end of the output.
 * 6. Return 1 to indicate successful output.
 */
int	ft_output_bytes(char *circular_buffer, size_t total_bytes, size_t byte_count)
{
	size_t	to_output;

	to_output = byte_count;
	if (total_bytes < byte_count)
		to_output = total_bytes;
	if (write(1, circular_buffer, to_output) == -1)
		return (0);
	ft_putchar('\n');
	return (1);
}
