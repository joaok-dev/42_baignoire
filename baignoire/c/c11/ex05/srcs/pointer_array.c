#include "../includes/do_op.h"

int (*ft_get_operator_function(char op))(int, int)
{
	if (op == '+')
		return (&ft_add);
	else if (op == '-')
		return (&ft_subtract);
	else if (op == '*')
		return (&ft_multiply);
	else if (op == '/')
		return (&ft_divide);
	else if (op == '%')
		return (&ft_modulo);
	return (0);
}
