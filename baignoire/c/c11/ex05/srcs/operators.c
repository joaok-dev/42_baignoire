#include "../includes/do_op.h"

int	ft_add(int a, int b)
{
	return (a + b);
}

int	ft_subtract(int a, int b)
{
	return (a - b);
}

int	ft_multiply(int a, int b)
{
	return (a * b);
}

int	ft_divide(int a, int b)
{
	if (b == 0)
	{
		ft_handle_division_by_zero();
		return (0);
	}
	return (a / b);
}

int	ft_modulo(int a, int b)
{
	if (b == 0)
	{
		ft_handle_modulo_by_zero();
		return (0);
	}
	return (a % b);
}
