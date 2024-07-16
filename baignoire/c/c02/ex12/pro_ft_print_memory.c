#include <unistd.h>

/*
 * Converts a given value to a specified base and stores the digits in a buffer.
 * Uses recursion to handle division and remainder, utilizing the call stack to
 * store digits in reverse order.
 *
 * Parameters:
 * - value: The value to be converted.
 * - base: The base to convert the value to (must be >= 2).
 * - buffer: Array to store the converted digits.
 * - buffer_index: Current index in the buffer for storing digits.
 */
void	convert_to_base(int value, int base, int buffer[], int buffer_index)
{
	if (base < 2)
		return;
	if (value >= base)
		convert_to_base(value / base, base, buffer, buffer_index +1);
	buffer[buffer_index] = value % base;
}

/*
 * Converts a number to the specified base and writes the digits to standard output.
 * Uses a buffer to store intermediate results and maps integers to their respective characters.
 *
 * Parameters:
 * - number: The number to be converted.
 * - base: The base to convert the number to.
 * - char_count: The number of characters to write to the output.
 */
void	ft_write_hex(unsigned int number, int base, int char_count)
{
	char	*hex;
	int		buffer[15];
	int		index;

	hex = "0123456789abcdef";
	index = -1;
	while (index++ < 14) // Initialize the buffer with zeros
		buffer[index] = 0;
	convert_to_base(number, base, buffer, 0); // Convert and store buffer in specfied base
	index = -1;
	while (index++ < char_count) // Write buffer in hexdecimal characters
		write(1, &hex[buffer[char_count - index]], 1);
}

/*
 * Writes a character to standard output if it is printable.
 * If the character is not printable, writes a dot ('.') instead.
 *
 * Parameters:
 * - c: Pointer to the character to be checked and written.
 */
void	ft_write_printable_char(char *c)
{
	if (*c >= 32 && *c <= 126)
		write(1, c, 1);
	else
		write(1, ".", 1);
}

/*
 * Prints a single line of memory, showing the address, hex values, and printable characters.
 *
 * Parameters:
 * - start_addr: The starting address of the memory block.
 * - size: The size of the memory block.
 * - curr_addr: The current address to start printing from.
 */
void	ft_print_memory_line(void *start_addr, unsigned int size, char *curr_addr)
{
	int	index;

	ft_write_hex((unsigned long)curr_addr, 16, 14);
	write(1, &": ", 2); // Print the current address in hexdecimal

	index = 0;
	while (index++ < 16)
	{
		if (start_addr + size <= (void *)(curr_addr + index -1))
			write(1, &"  ", 2); // Print spaces if beyond memory limit
		else
			ft_write_hex((unsigned char)*(curr_addr + index - 1), 16, 1);
		if (index % 2 == 0)
			write(1, &" ", 1); // Add space after every two hex values
	}

	index = 0;
	while (index++ < 16) // Print the printable chars or dots for non-printable
		if (start_addr + size > (void *)(curr_addr + index -1))
			ft_write_printable_char((char *)(curr_addr + index -1));
}

/*
 * Iterates over the memory block starting at addr and prints its content.
 * Prints the memory in blocks of 16 bytes, showing the address, hex values,
 * and printable characters for each block.
 *
 * Parameters:
 * - addr: The starting address of the memory block.
 * - size: The size of the memory block.
 *
 * Returns:
 * - The starting address of the memory block.
 */
void	*ft_print_memory(void *addr, unsigned int size)
{
	char *curr_addr;

	curr_addr = (char *)addr;
	while ((void *)curr_addr < (addr + size))
	{
		ft_print_memory_line(addr, size, curr_addr);
		write(1, &"\n", 1);
		curr_addr += 16;
	}
	return (addr);
}

int	main(void)
{
	char	data[] = "Hello, World! This is a test of the memory display function.";

	ft_print_memory(data, sizeof(data));
	return (0);
}
