#include <stdlib.h>

int	ft_intlen(int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
/*
 * ft_itoa - Converts an integer to a null-terminated string
 *
 * This function converts an integer 'nbr' into a string representation.
 * It handles negative numbers by including a '-' sign at the beginning
 * of the string. The function dynamically allocates memory for the string.
 *
 * @nbr: The integer to be converted
 *
 * Return: A pointer to the newly created string, or NULL if allocation fails
 *
 * Flow:
 * 1. Calculate the length of the integer including the sign if negative
 * 2. Allocate memory for the string, including space for the null terminator
 * 3. Populate the string with digits from the end to the start
 * 4. Add a negative sign if the number is negative
 * 5. Return the pointer to the start of the string
 */

char	*ft_itoa(int nbr)
{
	char	*result;
	char	*ptr;
	int		len;

	len = ft_intlen(nbr);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ptr = result + len;
	*ptr = '\0';
	if (nbr < 0)
	{
		*result = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		*--ptr = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}
