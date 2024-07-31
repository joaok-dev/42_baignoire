/*
 * ft_strcmp - Compares two strings lexicographically
 *
 * This function compares two strings character by character
 * until a difference is found or the end of a string is reached.
 *
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 *
 * Flow:
 * 1. While characters in both strings are equal and not null:
 *    a. Move to the next character in both strings
 * 2. Return the difference between the first differing characters,
 *    or 0 if strings are identical
 */
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
