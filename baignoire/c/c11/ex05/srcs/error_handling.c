#include "../includes/do_op.h"

void	ft_handle_division_by_zero(void)
{
	write(1, "Stop : division by zero\n", 24);
}

void	ft_handle_modulo_by_zero(void)
{
	write(1, "Stop : modulo by zero\n", 22);
}

void	ft_handle_invalid_operator(void)
{
	write(1, "0\n", 2);
}
