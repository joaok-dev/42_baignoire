#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

int	main(void)
{
	int	n;
	int	next_prime;

	printf("Enter a number to find the next prime: ");
	scanf("%d", &n);
	next_prime = ft_find_next_prime(n);
	printf("The next prime number greater or equal to %d is %d\n",
		n, next_prime);
	return (0);
}
