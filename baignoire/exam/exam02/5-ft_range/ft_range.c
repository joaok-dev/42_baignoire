#include <stdlib.h>

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
