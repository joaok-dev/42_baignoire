#include <stdio.h>

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

void	ft_rev_int_tab(int *tab, int size)
{
	int	i, tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}
