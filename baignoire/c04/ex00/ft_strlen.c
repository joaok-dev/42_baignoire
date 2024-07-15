#include <stdio.h>

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

int	main(void)
{
	char	str1[] = "Joao Kennedy";
	char	str2[] = "";
	char	str3[] = "42!";

	printf("Length of '%s': %d\n", str1, ft_strlen(str1));
	printf("Length of '%s': %d\n", str2, ft_strlen(str2));
	printf("Length of '%s': %d\n", str3, ft_strlen(str3));
}
