#include "../includes/do_op.h"

void	ft_itoa(int n, char *buffer)
{
	int		temp;
	char	*ptr;

	ptr = buffer;
	if (n == 0)
		*ptr++ = '0';
	else
	{
		if (n < 0)
		{
			*ptr++ = '-';
			n = -n;
		}
		temp = n;
		while (temp > 0)
		{
			ptr++;
			temp /= 10;
		}
		*ptr = '\0';
		while (n > 0)
		{
			*--ptr = (n % 10) + '0';
			n /= 10;
		}
	}
}

void	ft_print_result(int result)
{
	char	buffer[12];

	ft_itoa(result, buffer);
	write(1, buffer, 12);
	write(1, "\n", 1);
}

void	ft_handle_operation(int num1, int num2, char op)
{
	int	(*operation)(int, int);
	int	result;

	operation = ft_get_operator_function(op);
	if (!operation)
	{
		ft_handle_invalid_operator();
		return ;
	}
	if ((op == '/' && num2 == 0) || (op == '%' && num2 == 0))
		return ;
	result = operation(num1, num2);
	ft_print_result(result);
}
