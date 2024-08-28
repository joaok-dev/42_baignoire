void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	**current;
	char	**next;
	char	*temp;
	int		sorted;

	if (!tab || !cmp)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		current = tab;
		next = tab + 1;
		while (*next)
		{
			if (cmp(*current, *next) > 0)
			{
				temp = *current;
				*current = *next;
				*next = temp;
				sorted = 0;
			}
			current++;
			next++;
		}
	}
}
