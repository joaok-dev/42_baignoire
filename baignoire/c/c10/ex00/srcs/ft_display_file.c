#include "../includes/ft.h"

/*
 * main - Entry point of the program
 *
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 1 on failure
 */
int	main(int argc, char *argv[])
{
	char	buffer[BUFFER_SIZE];

	if (ft_validate_args(argc) != 0)
		return (1);
	if (ft_reading_file(argv[1], buffer) != 0)
		return (1);
	return (0);
}
