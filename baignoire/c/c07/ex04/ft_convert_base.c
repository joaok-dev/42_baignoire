#include <stdlib.h>

/*
 * ft_strlen - Calculates the length of a null-terminated string
 *
 * This function iterates through the input string until it reaches
 * the null terminator, counting the number of characters.
 * It uses pointer arithmetic to calculate the length.
 *
 * @str: The input string whose length is to be calculated
 *
 * Return: The number of characters in the string, excluding the null terminator
 *
 * Flow:
 * 1. Initialize a pointer to the start of the string
 * 2. Increment the pointer until it reaches the null terminator
 * 3. Calculate and return the difference between the final and initial positions
 */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

/*
 * ft_check_base - Validates the given base string
 *
 * This function checks if the provided base string is valid for number
 * representation. It ensures the base has at least 2 characters and
 * contains no duplicates or special characters ('+', '-', space, or whitespace).
 *
 * @base: The base string to be validated
 *
 * Return: 1 if the base is valid, 0 otherwise
 *
 * Flow:
 * 1. Check if the base length is at least 2
 * 2. Iterate through each character in the base
 * 3. Check for invalid special characters
 * 4. Ensure each character is unique within the base
 * 5. Return the validity status
 */
int	ft_check_base(char *base)
{
	char	*ptr;
	char	*check;

	if (ft_strlen(base) < 2)
		return (0);
	ptr = base;
	while (*ptr)
	{
		if (*ptr == '+' || *ptr == '-' || *ptr == ' '
			|| (*ptr >= '\t' && *ptr <= '\r'))
			return (0);
		check = ptr + 1;
		while (*check)
		{
			if (*ptr == *check)
				return (0);
			check++;
		}
		ptr++;
	}
	return (1);
}

/*
 * ft_atoi_base - Converts a string to an integer using a specified base
 *
 * This function converts a string representation of a number in a given base
 * to its integer value. It handles leading whitespace, signs, and validates
 * each character against the provided base.
 *
 * @str: The string to be converted
 * @base: The base string defining the number system
 *
 * Return: The converted integer value
 *
 * Flow:
 * 1. Initialize result and sign
 * 2. Skip leading whitespace
 * 3. Parse sign characters ('+' or '-')
 * 4. Convert each valid character to its numeric value in the given base
 * 5. Accumulate the result, applying the base arithmetic
 * 6. Return the final result with the appropriate sign
 */
int	ft_atoi_base(char *str, char *base)
{
	int		result;
	int		sign;
	int		base_len;
	char	*ptr;

	result = 0;
	sign = 1;
	base_len = ft_strlen(base);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		ptr = base;
		while (*ptr && *ptr != *str)
			ptr++;
		if (!*ptr)
			break ;
		result = result * base_len + (ptr - base);
		str++;
	}
	return (result * sign);
}

/*
 * ft_itoa_base - Converts an integer to a string in a specified base
 *
 * This function converts an integer into its string representation
 * using the provided base. It handles negative numbers and dynamically
 * allocates memory for the resulting string.
 *
 * @nbr: The integer to be converted
 * @base_to: The base string defining the number system for conversion
 *
 * Return: A pointer to the newly created string, or NULL if allocation fails
 *
 * Flow:
 * 1. Calculate the length of the base and the resulting string
 * 2. Allocate memory for the string, including space for sign and null terminator
 * 3. Handle special case for zero
 * 4. Convert the absolute value of the number to the specified base
 * 5. Add the negative sign if necessary
 * 6. Return the pointer to the start of the string
 */
char	*ft_itoa_base(int nbr, char *base_to)
{
	char	*result;
	char	*ptr;
	char	*base_end;
	int		len;
	int		temp;
	int		is_negative;

	base_end = base_to;
	while (*base_end)
		base_end++;
	len = 1;
	temp = nbr;
	while (temp / (base_end - base_to))
	{
		temp /= (base_end - base_to);
		len++;
	}
	is_negative = 0;
	if (nbr < 0)
	{
		is_negative = 1;
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ptr = result + len;
	*ptr = '\0';
	if (nbr == 0)
		*--ptr = *base_to;
	while (nbr)
	{
		if (nbr > 0)
			*--ptr = *(base_to + (nbr % (base_end - base_to)));
		else
			*--ptr = *(base_to - (nbr % (base_end - base_to)));
		nbr /= (base_end - base_to);
	}
	if (is_negative)
		*--ptr = '-';
	return (result);
}

/*
 * ft_convert_base - Converts a number from one base to another
 *
 * This function takes a number as a string in the source base, converts it
 * to an integer, and then converts that integer to a string in the target base.
 * It utilizes ft_check_base, ft_atoi_base, and ft_itoa_base functions.
 *
 * @nbr: The number as a string in the source base
 * @base_from: The source base string
 * @base_to: The target base string
 *
 * Return: A pointer to the newly created string in the target base,
 *         or NULL if either base is invalid or if memory allocation fails
 *
 * Flow:
 * 1. Validate both source and target bases
 * 2. Convert the number from the source base to an integer
 * 3. Convert the integer to a string in the target base
 * 4. Return the resulting string
 */
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(num, base_to);
	return (result);
}
