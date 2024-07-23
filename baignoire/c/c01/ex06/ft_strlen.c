#include <stdio.h>

int		ft_strlen(char *str);

int	main(void)
{
	ft_strlen("Joao Kennedy");
	printf("%d", ft_strlen("Joao Kennedy"));
}

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
