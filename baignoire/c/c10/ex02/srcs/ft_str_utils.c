#include "../includes/ft.h"

/**
 * @brief Calculates the length of a given string.
 * This function determines the number of characters in a string by iterating
 * through it and counting each character until the null terminator is reached.
 *
 * @param str The input string whose length is to be calculated.
 *
 * @return size_t The length of the input string as a non-negative integer.
 *
 * Flow:
 * 1. Initialize a length counter to 0.
 * 2. Start at the beginning of the input string.
 * 3. Iterate through each character of the string:
 *    a. If the current character is not the string terminator, increment the
 *       length counter.
 *    b. Move to the next character.
 * 4. When the string terminator is reached, stop iterating.
 * 5. Return the final value of the length counter.
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;
	char	*ptr;

	len = 0;
	ptr = (char *)str;
	while (*ptr)
	{
		len++;
		ptr++;
	}
	return (len);
}

/**
 * @brief Copies the source string to the destination string.
 * This function copies each character from the source string to the destination
 * string, including the null terminator.
 *
 * @param dest The destination buffer where the source string will be copied.
 * @param src The source string to be copied.
 *
 * @return char* Pointer to the destination string.
 *
 * Flow:
 * 1. Initialize pointers for destination and source strings.
 * 2. Iterate through each character of the source string:
 *    a. Copy the current character to the destination string.
 *    b. Move to the next character in both strings.
 * 3. Once the null terminator is copied, stop iterating.
 * 4. Return the destination string.
 */
char	*ft_strcpy(char *dest, const char *src)
{
	char	*d;
	char	*s;

	d = dest;
	s = (char *)src;
	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return (dest);
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
 * @brief Duplicates a given string.
 * This function creates a copy of the input string by allocating memory for
 * the new string and copying each character from the input string.
 *
 * @param str The input string to be duplicated.
 *
 * @return char* Pointer to the newly allocated duplicate string.
 *               NULL if memory allocation fails.
 *
 * Flow:
 * 1. Calculate the length of the input string.
 * 2. Allocate memory for the new string, including space for the null
 * terminator.
 * 3. If memory allocation fails, return NULL.
 * 4. Copy each character from the input string to the new string.
 * 5. Add a null terminator to the end of the new string.
 * 6. Return the duplicate string.
 */
char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	len;
	char	*ptr;

	len = ft_strlen(str);
	dup = (char *)malloc((len +1) * sizeof(char));
	if (!dup)
		// TODO: Add errono error handling
		return (NULL);
	ptr = dup;
	while (*str)
	{
		*ptr = *str;
		ptr++;
		str++;
	}
	*ptr = '\0';
	return (dup);
}
