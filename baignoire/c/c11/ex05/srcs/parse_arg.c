#include "../includes/do_op.h"

int	ft_parse_arg(int argc, char **argv, int *num1, int *num2, char *op)
{
	char	*ptr;

	if (argc != 4)
		return (0);
	*num1 = 0;
	*num2 = 0;
	ptr = argv[1];
	while (*ptr)
	{
		*num1 = *num1 * 10 + (*ptr - '0');
		ptr++;
	}
	*op = *argv[2];
	ptr = argv[3];
	while (*ptr)
	{
		*num2 = *num2 * 10 + (*ptr - '0');
		ptr++;
	}
	if (*op != '+' && *op != '-' && *op != '*' && *op != '/' && *op != '%')
		return (0);
	return (1);
}
