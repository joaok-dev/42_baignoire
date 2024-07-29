#include <stdio.h>
#include <stdlib.h>

/* Function to allocate and initialize a range of integers from min to max */
int	ft_ultimate_range(int **range, int min, int max)
{
	int	*result;
	int	*ptr;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	result = (int *)malloc(size * sizeof(int));
	if (!result)
	{
		*range = NULL;
		return (-1);
	}
	ptr = result;
	while (min < max)
		*ptr++ = min++;
	*range = result;
	return (size);
}

int	main(void)
{
	int	min;
	int	max;
	int	*range;
	int	size;
	int	*ptr;

	min = 3;
	max = 10;
	size = ft_ultimate_range(&range, min, max);
	if (size == -1)
	{
		printf("Error: Memory allocation failed.\n");
		return (1);
	}
	else if (size == 0)
	{
		printf("No range to allocate.\n");
		return (0);
	}
	ptr = range;
	while (ptr < range + size)
		printf("%d ", *ptr++);
	printf("\n");
	free(range);
	return (0);
}
