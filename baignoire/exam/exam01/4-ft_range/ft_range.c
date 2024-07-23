#include <stdlib.h>
/*
 * ft_range - Creates an array of integers from start to end (inclusive)
 *
 * This function allocates memory for an array and fills it with consecutive
 * integers from 'start' to 'end', including both ends. It handles both
 * ascending and descending ranges.
 *
 * @start: The first number in the range
 * @end: The last number in the range
 *
 * Return: A pointer to the newly created array, or NULL if allocation fails
 *
 * Flow:
 * 1. Calculate the size of the range (accounting for both directions)
 * 2. Allocate memory for the array
 * 3. Fill the array with consecutive numbers
 * 4. Return the pointer to the start of the array
 */
int	*ft_range(int start, int end)
{
	int	size;
	int	*array;
	int	*ptr;

	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	array = (int *)malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	ptr = array;
	while (size > 0)
	{
		*ptr = start;
		if (start > end)
			start--;
		else
			start++;
		ptr++;
		size--;
	}
	return (array);
}
