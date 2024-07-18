void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_strrev(char *str)
{
	char	*start;
	char	*end;

	start = str;
	while (*str)
		str++;
	end = str - 1;
	while (start < end)
	{
		ft_swap(start, end);
		start++;
		end--;
	}
	return (str);
}
