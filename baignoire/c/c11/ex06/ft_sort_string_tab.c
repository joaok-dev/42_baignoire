void	ft_sort_string_tab(char **tab)
{
	char	**current;
	char	**next;
	char	*temp;
	int		sorted;

	if (!tab)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		current = tab;
		next = tab + 1;
		while (*next)
		{
			if (**current > **next)
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
