#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}

int	main(void)
{
	printf("%i\n", ft_iterative_power(3, 4));
	printf("%i\n", ft_iterative_power(2, 10));
}
