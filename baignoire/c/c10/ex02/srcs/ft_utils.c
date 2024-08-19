#include "../includes/ft.h"

/**
 * @brief Converts a string to an integer.
 * This function parses a string and converts it into an integer, handling
 * optional leading spaces and a sign character.
 *
 * @param str The string to be converted.
 *
 * @return int The integer representation of the string.
 *
 * Flow:
 * 1. Initialize result to 0 and sign to 1.
 * 2. Skip leading whitespace characters.
 * 3. Check for a sign character ('-' or '+') and update sign accordingly.
 * 4. Iterate through the digits of the string:
 *    a. Update result by multiplying by 10 and adding the current digit.
 * 5. Return the result multiplied by the sign.
 */
int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	char	*ptr;

	result = 0;
	sign = 1;
	ptr = (char *)str;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + (*ptr - '0');
		ptr++;
	}
	return (result * sign);
}

/**
 * @brief Returns the minimum of two size_t values.
 * This function compares two size_t values and returns the smaller one.
 *
 * @param a The first value to compare.
 * @param b The second value to compare.
 *
 * @return size_t The smaller of the two values.
 *
 * Flow:
 * 1. Compare the two values.
 * 2. Return the smaller value.
 */
size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * @brief Copies memory from source to destination.
 * This function copies n bytes from the memory area src to the memory area dest.
 *
 * @param dest The destination buffer where the data is copied.
 * @param src The source buffer from which the data is copied.
 * @param n The number of bytes to copy.
 *
 * @return void* Pointer to the destination buffer.
 *
 * Flow:
 * 1. Initialize destination and source pointers.
 * 2. Copy each byte from src to dest until n bytes are copied.
 * 3. Return the destination pointer.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

/**
 * @brief Moves a block of memory, handling overlapping regions.
 * This function copies n bytes from the memory area src to the memory
 * area dest.
 * The memory areas may overlap: copying takes place as though the bytes
 * in src are first copied into a temporary array that does not overlap src
 * or dest, and the bytes are then copied from the temporary array to dest.
 *
 * @param dest The destination buffer where the data is copied.
 * @param src The source buffer from which the data is copied.
 * @param n The number of bytes to copy.
 *
 * @return void* Pointer to the destination buffer.
 *
 * Flow:
 * 1. Initialize pointers d and s to the destination and source buffers,
 * respectively.
 * 2. If the destination address is less than the source address:
 *    a. Copy bytes from src to dest from beginning to end.
 * 3. If the destination address is greater than or equal to the source address:
 *    a. Adjust pointers to the end of the buffers.
 *    b. Copy bytes from src to dest from end to beginning.
 * 4. Return the destination pointer.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
