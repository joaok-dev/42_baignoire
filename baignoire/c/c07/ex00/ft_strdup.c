#include <stdlib.h>

/* Calclates the lenght of a string */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}


/* Creates a duplicate of the input string */
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
