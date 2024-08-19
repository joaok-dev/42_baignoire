#include "../includes/ft.h"

int	main(int argc, char **argv)
{
	t_hexdump	hexdump;

	if (!ft_parse_arguments(argc, argv, &hexdump))
		return (1);
	ft_process_file(&hexdump);
	return (0);
}
