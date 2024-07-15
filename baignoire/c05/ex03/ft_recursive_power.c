#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	if (power > 0)
		result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}

int	main(void)
{
	printf("2^3 = %d\n", ft_recursive_power(2, 3));
	printf("2^-3 = %d\n", ft_recursive_power(2, -3));
	printf("0^0 = %d\n", ft_recursive_power(0, 0));
	printf("2^0 = %d\n", ft_recursive_power(2, 0));
	printf("-2^3 = %d\n", ft_recursive_power(-2, 3));
	return (0);
}
