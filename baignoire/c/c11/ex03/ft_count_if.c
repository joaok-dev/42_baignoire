int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;

	count = 0;
	while (length--)
	{
		if (f(*tab) != 0)
			count++;
		tab++;
	}
	return (count);
}
