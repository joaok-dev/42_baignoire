#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*ptr, *result;

	if (min >= max)
		return (NULL);
	result = (int *) malloc((max - min) * sizeof(int));
	if (result == NULL)
		return (NULL);
	ptr = result;
	while (min < max)
	{
		*ptr = min;
		ptr++;
		min++;
	}
	return (result);
}

int	main(void)
{
	int	min, max, *range, *ptr;

	min = 3;
	max = 10;
	range = ft_range(min, max);
	if (range == NULL)
	{
		printf("Error: Memory allocation failed or invalid range.\n");
		return (1);
	}
	ptr = range;
	while (ptr < range + (max - min))
	{
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");
	free(range);
	return (0);
}
