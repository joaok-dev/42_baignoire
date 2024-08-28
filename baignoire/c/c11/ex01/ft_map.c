#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	*ptr;

	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (NULL);
	ptr = result;
	while (length--)
	{
		*ptr = f(*tab);
		ptr++;
		tab++;
	}
	return (result);
}
