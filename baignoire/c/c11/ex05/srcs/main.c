#include "../includes/do_op.h"

int	main(int argc, char **argv)
{
	int		num1;
	int		num2;
	char	op;

	if (!ft_parse_arg(argc, argv, &num1, &num2, &op))
		return (0);
	ft_handle_operation(num1, num2, op);
	return (0);
}
