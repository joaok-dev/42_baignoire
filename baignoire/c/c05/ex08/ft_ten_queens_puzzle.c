#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int		is_safe(int board[], int col)
{
	int	i;
	int	diff;

	i = 0;
	while (i < col)
	{
		diff = board[i] - board[col];
		if (diff == 0 || diff == i - col || diff == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int board[])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

void	solve_queens(int board[], int col, int *count)
{
	int	row;

	if (col == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		board[col] = row;
		if (is_safe(board, col))
			solve_queens(board, col + 1, count);
		row++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	solve_queens(board, 0, &count);
	return (count);
}

int	main(void)
{
	int	total_solutions;

	total_solutions = ft_ten_queens_puzzle();
	ft_putchar('\n');
	ft_putnbr(total_solutions);
	ft_putchar('\n');
	return (0);
}
