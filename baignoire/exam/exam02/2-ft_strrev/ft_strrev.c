/**
 * Reverses a string in place.
 *
 * @param str The string to be reversed.
 * @return A pointer to the reversed string.
 */
char	*ft_strrev(char *str)
{
	char	*start;
	char	*end;
	char	tmp;

	if (!str)
		return (str);
	start = str;
	end = str;
	while (*end)
		end--;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
	return (str);
}
