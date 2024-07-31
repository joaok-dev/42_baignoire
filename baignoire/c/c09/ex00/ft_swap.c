/*
 * ft_swap - Swaps the values of two integers
 *
 * This function exchanges the values pointed to by two integer pointers.
 * It uses a temporary variable to perform the swap.
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Flow:
 * 1. Store the value pointed to by 'a' in a temporary variable
 * 2. Assign the value pointed to by 'b' to the location pointed to by 'a'
 * 3. Assign the temporary value to the location pointed to by 'b'
 */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
