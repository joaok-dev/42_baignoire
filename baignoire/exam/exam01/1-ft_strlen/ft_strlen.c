#include <stdio.h>

int	ft_strelen(char *str)
{
	char	*s;

	s = str;
	while (*str)
		str++;
	return (str - s);
}

int	main(void)
{
	char	*name;
	int		len;

	name = "Joao Oliveira";
	len = ft_strelen(name);
	printf("%d\n", len);
	return (0);
}
