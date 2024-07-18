#include <stdio.h>

void		ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	num1, num2;

	num1 = 42;
	num2 = 3;
	ft_ultimate_div_mod(&num1, &num2);
	printf("div = %d\n", num1);
	printf("mod = %d\n", num2);
}

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (b && *b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
}
