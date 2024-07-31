/*
 * ft_strlen - Calculates the length of a string
 *
 * This function counts the number of characters in a null-terminated string
 * by iterating through it until the null terminator is reached.
 *
 * @str: The input string whose length is to be calculated
 *
 * Return: The number of characters in the string (excluding null terminator)
 *
 * Flow:
 * 1. Start with the input string pointer
 * 2. While the current character is not null:
 *    a. Move to the next character
 * 3. Return the difference between the final and initial pointer positions
 */
int	ft_strlen(char *str)
{
	char *s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
