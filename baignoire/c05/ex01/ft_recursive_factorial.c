#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	if (nb > 0)
		result *= nb * ft_recursive_factorial(nb -1);
	return (result);
}

int	main(void)
{
	printf("%i\n", ft_recursive_factorial(0));
	printf("%i\n", ft_recursive_factorial(1));
	printf("%i\n", ft_recursive_factorial(3));
	printf("%i\n", ft_recursive_factorial(5));
	printf("%i\n", ft_recursive_factorial(9));
	printf("%i\n", ft_recursive_factorial(-5));
	return (0);
}
