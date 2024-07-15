#include <stdio.h>

void		ft_swap(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 24;
	b = 42;
	printf("Before:\n");
	printf("A = %d\n", a);
	printf("B = %d\n", b);
	ft_swap(&a, &b);
	printf("After:\n");
	printf("A = %d\n", a);
	printf("B = %d\n", b);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
