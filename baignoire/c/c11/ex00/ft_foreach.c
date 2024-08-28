void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	while(lenght--)
	{
		f(*tab);
		tab++;
	}
}
