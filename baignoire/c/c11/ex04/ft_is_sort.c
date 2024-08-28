int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	ascending;
	int	descending;

	if (length < 2)
		return (1);
	ascending = 1;
	descending = 1;
	while (--length > 0)
	{
		if (f(*tab, *(tab + 1)) > 0)
			ascending = 0;
		if (f(*tab, *(tab + 1)) < 0)
			descending = 0;
		tab++;
	}
	return (ascending || descending);
}
