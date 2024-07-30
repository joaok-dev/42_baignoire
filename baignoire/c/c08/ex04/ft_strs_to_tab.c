#include <stdlib.h>
#include "ft_stock_str.h"

/*
 * ft_strlen - Calculates the length of a string
 *
 * This function iterates through the input string, counting
 * characters until it reaches the null terminator.
 *
 * @str: The input string
 *
 * Return: The length of the string
 *
 * Flow:
 * 1. Initialize length counter to 0
 * 2. Iterate through each character in the string
 * 3. Increment length for each character
 * 4. Return the final length
 */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

/*
 * ft_strdup - Creates a duplicate of the input string
 *
 * This function allocates memory for a new string and copies
 * the contents of the input string into it.
 *
 * @src: The source string to duplicate
 *
 * Return: A pointer to the newly allocated string, or NULL if allocation fails
 *
 * Flow:
 * 1. Check if input string is NULL
 * 2. Allocate memory for the new string
 * 3. Copy characters from source to new string
 * 4. Null-terminate the new string
 * 5. Return the pointer to the new string
 */
char	*ft_strdup(char *src)
{
	char	*dup;
	char	*start;

	if (!src)
		return (NULL);
	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	start = dup;
	while (*src)
		*dup++ = *src++;
	*dup = '\0';
	return (start);
}

/*
 * ft_free_all - Frees all allocated memory in an array of t_stock_str
 *
 * This function iterates through the array, freeing the copy member
 * of each structure, then frees the array itself.
 *
 * @tab: Pointer to the array of t_stock_str
 * @count: Number of elements to free
 *
 * Flow:
 * 1. Iterate through each element up to count
 * 2. Free the copy member of each structure
 * 3. Free the entire array
 */
void	ft_free_all(t_stock_str *tab, int count)
{
	t_stock_str	*current;

	current = tab;
	while (count--)
	{
		free(current->copy);
		current++;
	}
	free(tab);
}

/*
 * ft_strs_to_tab - Converts an array of strings to an array of t_stock_str
 *
 * This function allocates memory for an array of t_stock_str structures,
 * fills each structure with data from the input string array, and handles
 * memory allocation errors.
 *
 * @ac: The number of strings in the input array
 * @av: The array of input strings
 *
 * Return: Pointer to the new array of t_stock_str, or NULL if allocation fails
 *
 * Flow:
 * 1. Allocate memory for the array of t_stock_str
 * 2. Iterate through each input string
 * 3. Fill each t_stock_str with string data
 * 4. Handle memory allocation errors
 * 5. Set the last element's str to NULL
 * 6. Return the pointer to the new array
 */
struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	t_stock_str	*current;
	char		**current_av;

	tab = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	current = tab;
	current_av = av;
	while (ac--)
	{
		current->str = *current_av;
		current->size = ft_strlen(current->str);
		current->copy = ft_strdup(current->str);
		if (!current->copy)
		{
			ft_free_all(tab, (current - tab));
			return (NULL);
		}
		current++;
		current_av++;
	}
	current->str = NULL;
	return (tab);
}
