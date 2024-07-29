#include <stdio.h>
#include <stdlib.h>

/* Create an array of integers from min to max (excluding max) */
int	*ft_range(int min, int max)
{
	int	*ptr;
	int	*result;

	if (min >= max)
		return (NULL);
	result = (int *) malloc((max - min) * sizeof(int));
	if (!result)
		return (NULL);
	ptr = result;
	while (min < max)
		*ptr++ = min++;
	return (result);
}

int	main(void)
{
	int	min;
	int	max;
	int	*range;
	int	*ptr;

	min = 3;
	max = 10;
	range = ft_range(min, max);
	if (!range)
	{
		printf("Error: Memory allocation failed or invalid range.\n");
		return (1);
	}
	ptr = range;
	while (ptr < range + (max - min))
		printf("%d ", *ptr++);
	printf("\n");
	free(range);
	return (0);
}
