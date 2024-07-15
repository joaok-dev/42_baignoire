#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int	main(void)
{
	printf("Fibonacci(0) = %d\n", ft_fibonacci(0));
	printf("Fibonacci(1) = %d\n", ft_fibonacci(1));
	printf("Fibonacci(2) = %d\n", ft_fibonacci(2));
	printf("Fibonacci(3) = %d\n", ft_fibonacci(3));
	printf("Fibonacci(4) = %d\n", ft_fibonacci(4));
	printf("Fibonacci(5) = %d\n", ft_fibonacci(5));
	printf("Fibonacci(-1) = %d\n", ft_fibonacci(-1));
	return (0);
}
