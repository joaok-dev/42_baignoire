#include "../includes/ft.h"

/**
 * @brief Writes a single character to standard output.
 * This function writes a single character to the standard output.
 *
 * @param c The character to be written.
 *
 * Flow:
 * 1. Use the write system call to output the character.
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * @brief Writes a string to standard output.

	* This function writes each character of the given string to the standard output.
 *
 * @param str The string to be written.
 *
 * Flow:
 * 1. Initialize a pointer to the start of the string.
 * 2. Iterate through each character in the string:
 *    a. Write the current character to standard output using ft_putchar.
 *    b. Move to the next character.
 */
void	ft_putstr(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		ft_putchar(*ptr);
		ptr++;
	}
}

/**
 * @brief Compares two strings lexicographically.
 * This function compares two strings character by character and returns the
 * difference between the first pair of characters that differ.
 *
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 *
 * @return int The difference between the first pair of differing characters.
 *             0 if the strings are equal.
 *
 * Flow:
 * 1. Initialize pointers for both strings.
 * 2. Iterate through both strings simultaneously:
 *    a. If the characters at the current position are equal, continue.
 *    b. If they differ or either string ends, stop iterating.
 * 3. Return the difference between the current characters.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
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
