void		ft_putchar(char c);

void	rush(int col, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((i == 0 && j == 0) || (i == row - 1 && j == col -1))
				ft_putchar('/');
			else if ((i == 0 && j == col -1) || (i == row - 1 && j == 0))
				ft_putchar('\\');
			else if ((i == 0 || i == row - 1) || (j == 0 || j == col - 1))
				ft_putchar('*');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}