#include "../includes/ft.h"

/**
 * @brief Processes a file for hexdump output.
 * This function reads data from the file specified in the hexdump structure,
 * formats the data into a hexdump output, and prints it.
 *

	* @param hexdump A pointer to the t_hexdump structure containing file descriptor
 *                and options.
 *
 * Flow:
 * 1. Initialize the buffer and offset.
 * 2. If reading from standard input (fd == 0):
 *    a. Read data into the buffer in a loop.
 *    b. Format and print each chunk of data.
 *    c. Update the offset.
 * 3. If reading from a file:
 *    a. Read data into the buffer in a loop.
 *    b. Format and print each chunk of data.
 *    c. Update the offset.
 *    d. If a read error occurs, print the error message and system error.
 *    e. Close the file.
 */
void	ft_process_file(t_hexdump *hexdump)
{
	unsigned char	buf[BUFFER_SIZE];
	ssize_t			bytes_read;
	size_t			offset;

	offset = 0;
	if (hexdump->fd == 0)
	{
		while ((bytes_read = ft_read_file(hexdump->fd, buf, BUFFER_SIZE)) > 0)
		{
			ft_format_and_print_chunk(buf, bytes_read, offset,
				hexdump->use_c_option);
			offset += bytes_read;
		}
	}
	else
	{
		while ((bytes_read = ft_read_file(hexdump->fd, buf, BUFFER_SIZE)) > 0)
		{
			ft_format_and_print_chunk(buf, bytes_read, offset,
				hexdump->use_c_option);
			offset += bytes_read;
		}
		if (bytes_read == -1)
		{
			ft_print_error(ERROR_READ);
			ft_print_system_error();
		}
		ft_close_file(hexdump->fd);
	}
}

/**
 * @brief Formats and prints a chunk of data for hexdump output.
 * This function formats a chunk of data into offset, hex, and ASCII
 * representations and prints it.
 *
 * @param buf The buffer containing the data to format.
 * @param len The length of the data in the buffer.
 * @param offset The offset of the data in the file.
 * @param use_c_option A flag indicating whether to use the -c option.
 *
 * Flow:
 * 1. Format the offset into a string.
 * 2. Format the data bytes into a hex string.
 * 3. Format the data bytes into an ASCII string.
 * 4. Print the formatted line.
 */
void	ft_format_and_print_chunk(const unsigned char *buf, size_t len,
		size_t offset, int use_c_option)
{
	char	offset_str[9];
	char	hex_str[49];
	char	ascii_str[17];

	ft_format_offset(offset_str, offset);
	ft_format_hex_bytes(hex_str, buf, len, use_c_option);
	ft_format_ascii_representation(ascii_str, buf, len);
	ft_print_line(offset_str, hex_str, ascii_str, use_c_option);
}

/**
 * @brief Formats the offset into a hexadecimal string.
 * This function converts an offset value into an 8-character hexadecimal
 * string representation.
 *
 * @param dest The destination buffer for the formatted offset string.
 * @param offset The offset value to format.
 *
 * Flow:
 * 1. Initialize index i to 7.
 * 2. Convert each digit of the offset to a hex character from right to left.
 * 3. Null-terminate the string.
 */
void	ft_format_offset(char *dest, size_t offset)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		*(dest + i) = HEX_CHARS[offset % 16];
		offset /= 16;
		i--;
	}
	*(dest + 8) = '\0';
}

/**
 * @brief Formats bytes into a hexadecimal string representation.
 * This function converts a buffer of bytes into a string of hexadecimal
 * characters, with optional grouping based on the -c option.
 *
 * @param dest The destination buffer for the formatted hex string.
 * @param buf The buffer containing the bytes to format.
 * @param len The length of the data in the buffer.
 * @param use_c_option A flag indicating whether to use the -c option.
 *
 * Flow:
 * 1. Initialize pointers to the end of the buffer and the destination string.
 * 2. Initialize byte_count to track the number of bytes processed.
 * 3. Iterate through each byte in the buffer:
 *    a. If -c option is used and byte_count is a multiple of 8, add a space.
 *    b. Convert the byte to hex and add to the destination string.
 *    c. Increment the buffer pointer and byte_count.
 * 4. Pad the remaining part of the destination string with spaces until
 *    BUFFER_SIZE is reached.
 * 5. Null-terminate the destination string.
 */
void	ft_format_hex_bytes(char *dest, const unsigned char *buf, size_t len,
		int use_c_option)
{
	const unsigned char	*buf_end;
	char				*dest_ptr;
	int					byte_count;

	buf_end = buf + len;
	dest_ptr = dest;
	byte_count = 0;
	while (buf < buf_end)
	{
		if (use_c_option && byte_count != 0 && byte_count % 8 == 0)
			*dest_ptr = ' ';
		*dest_ptr++ = HEX_CHARS[(*buf) / 16];
		*dest_ptr++ = HEX_CHARS[(*buf) % 16];
		*dest_ptr++ = ' ';
		buf++;
		byte_count++;
	}
	while (byte_count < BUFFER_SIZE)
	{
		if (use_c_option && byte_count != 0 && byte_count % 8 == 0)
			*dest_ptr++ = ' ';
		*dest_ptr++ = ' ';
		*dest_ptr++ = ' ';
		*dest_ptr++ = ' ';
		byte_count++;
	}
	*dest_ptr = '\0';
}

/**
 * @brief Formats bytes into an ASCII string representation.
 * This function converts a buffer of bytes into a string of ASCII characters,
 * replacing non-printable characters with a dot ('.').
 *
 * @param dest The destination buffer for the formatted ASCII string.
 * @param buf The buffer containing the bytes to format.
 * @param len The length of the data in the buffer.
 *
 * Flow:
 * 1. Iterate through each byte in the buffer:
 *    a. If the byte is a printable ASCII character, add it to the destination.
 *    b. If the byte is not printable, add a dot ('.') to the destination.
 * 2. Pad the remaining part of the destination string with spaces until
 *    BUFFER_SIZE is reached.
 * 3. Null-terminate the destination string.
 */
void	ft_format_ascii_representation(char *dest, const unsigned char *buf,
		size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (*(buf + i) >= 32 && *(buf + i) <= 126)
			*(dest + i) = *(buf + i);
		else
			*(dest + i) = '.';
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		*(dest + i) = ' ';
		i++;
	}
	*(dest + i) = '\0';
}

/**
 * @brief Prints a formatted hexdump line.
 * This function prints a line of hexdump output, including the offset, hex
 * representation, and optional ASCII representation.
 *
 * @param offset_str The string representation of the offset.
 * @param hex_str The string representation of the hex bytes.
 * @param ascii_str The string representation of the ASCII characters.
 * @param use_c_option A flag indicating whether to use the -c option.
 *
 * Flow:
 * 1. Print the offset string.
 * 2. Print two spaces.
 * 3. Print the hex string.
 * 4. If the -c option is used:
 *    a. Print a separator and the ASCII string.
 * 5. Print a newline character.
 */
void	ft_print_line(const char *offset_str, const char *hex_str,
		const char *ascii_str, int use_c_option)
{
	ft_putstr(offset_str);
	ft_putstr("  ");
	ft_putstr(hex_str);
	if (use_c_option)
	{
		ft_putstr(" |");
		ft_putstr(ascii_str);
		ft_putstr("|");
	}
	ft_putchar('\n');
}
