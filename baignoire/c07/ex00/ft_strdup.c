#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	if (! *str)
		return (0);
	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	char	*error;
	char	*start;

	error = "Memory allocation failure.\n";
	dup = malloc(1 + ft_strlen(src) * sizeof(char));
	if (dup == NULL)
	{
		ft_putstr(error);
		exit (1);
	}
	start = dup;
	while (*src)
	{
		*dup = *src;
		dup++;
		src++;
	}
	*dup = '\0';
	return (start);
}

int	main(void)
{
	char	original[] = "Joao Kennedy";
	char	*duplicate;

	duplicate = ft_strdup(original);
	if (duplicate != NULL)
	{
		ft_putstr(duplicate);
		ft_putstr("\n");
		free(duplicate);
	}
	return (0);
}
