#include <stdio.h>

void		ft_swap(int *a, int *b);
void		ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	len, i;
	int	array[5] = {1, 2, 3, 4, 5};

	len = sizeof(array) / sizeof(array[0]);
	i = 0;
	while (i < len)
	{
		printf("%d\n", array[i]);
		i++;
	}
	printf("\n");
	ft_rev_int_tab(array, len);
	i = 0;
	while (i < len)
	{
		printf("%d\n", array[i]);
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	*start;
	int	*end;

	start = tab;
	end = tab + size - 1;
	while (start < end)
	{
		ft_swap(start, end);
		start++;
		end--;
	}
}
