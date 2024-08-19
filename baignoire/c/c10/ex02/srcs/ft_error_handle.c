#include "../includes/ft.h"

/**
 * @brief Prints a custom error message to standard error.
 * This function writes each character of the provided error message to the
 * standard error stream, followed by a newline.
 *
 * @param message The error message string to be printed.
 *
 * Flow:
 * 1. Initialize a pointer to the start of the message string.
 * 2. Iterate through each character of the message:
 *    a. Write the current character to the standard error stream.
 *    b. Move to the next character.
 * 3. After the message is printed, write a newline character to standard error.
 */
void	ft_print_error(const char *message)
{
	char	*ptr;

	ptr = (char *)message;
	while (*ptr)
	{
		write(2, ptr, 1);
		ptr++;
	}
	write(2, "\n", 1);
}

/**
 * @brief Prints the system error message to standard error.
 * This function retrieves the current system error message using strerror and
 * writes it to the standard error stream, preceded by a ": " separator and
 * followed by a newline.
 *
 * Flow:
 * 1. Retrieve the system error message string using strerror and errno.
 * 2. Write the ": " separator to the standard error stream.
 * 3. Initialize a pointer to the start of the error message string.
 * 4. Iterate through each character of the error message:
 *    a. Write the current character to the standard error stream.
 *    b. Move to the next character.
 * 5. After the error message is printed, write a newline character to
 * standard error.
 */
void	ft_print_system_error(void)
{
	char	*error_msg;
	char	*ptr;

	error_msg = strerror(errno);
	ptr = error_msg;
	write(2, ": ", 2);
	while (*ptr)
	{
		write(2, ptr, 1);
		ptr++;
	}
	write(2, "\n", 1);
}
