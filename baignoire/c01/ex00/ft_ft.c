#include <stdio.h>

void		ft_ft(int *nbr);

int	main(void)
{
	int	a;
	int	*ptr;

	a = 1;
	printf("Before %d\n", a);
	ptr = &a;
	ft_ft(ptr);
	printf("After %d\n", a);
	return (0);
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
