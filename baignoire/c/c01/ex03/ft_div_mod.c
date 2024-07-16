#include <stdio.h>

void		ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	num1, num2, result_div, result_mod;

	num1 = 42;
	num2 = 2;
	ft_div_mod(num1, num2, &result_div, &result_mod);
	printf("div = %d\n", result_div);
	printf("mod = %d\n", result_mod);
	return (0);
}

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}
