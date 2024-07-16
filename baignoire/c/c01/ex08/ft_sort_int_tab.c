#include <stdio.h>

void		ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	len, i;
	int array[6] = {12, 33, 84, 1, 4, 7};

	len = sizeof(array) / sizeof(array[0]);
	i = 0;
	while (i < len)
	{
		printf("%d, ", array[i]);
		i++;
	}
	printf("\n");
	ft_sort_int_tab(array, len);
	i = 0;
	while (i < len)
	{
		printf("%d, ", array[i]);
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i, j, tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
