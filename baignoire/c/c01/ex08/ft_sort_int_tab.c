#include <stdio.h>

void		ft_sort_int_tab(int *tab, int size);
void		ft_swap(int *a, int *b);

int	main(void)
{
	int	len;
	int	i;
	int	array[6] = {12, 33, 84, 1, 4, 7};

	len = sizeof(array) / sizeof(array[0]);
	i = 0;
	while (i < len)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
	ft_sort_int_tab(array, len);
	i = 0;
	while (i < len)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*Bubble sort algo */
void	ft_sort_int_tab(int *tab, int size)
{
	int	*inner_ptr;
	int	last_unsorted_index;
	int	iterations_completed;

	last_unsorted_index = size - 1;
	iterations_completed = 0;
	while (iterations_completed < last_unsorted_index)
	{
		inner_ptr = tab;
		while (inner_ptr < tab + last_unsorted_index - iterations_completed)
		{
			if (*inner_ptr > *(inner_ptr + 1))
				ft_swap(inner_ptr, inner_ptr + 1);
			inner_ptr++;
		}
		iterations_completed++;
	}
}
