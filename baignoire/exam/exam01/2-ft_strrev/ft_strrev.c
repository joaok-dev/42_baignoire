int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_swap_char(char *a, char *b)
{
	char	*tmp;

	tmp = a;
	a = b;
	b = tmp;
}

char	*ft_strrev(char *str)
{
	char	*left;
	char	*right;

	left = str;
	right = str + ft_strlen(str) - 1;
	while (left < right)
	{
		ft_swap_char(left, right);
		left++;
		right--;
	}
	return (str);
}
