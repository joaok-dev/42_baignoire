#include <stdio.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	str1[] = "apple";
	char	str2[] = "apricot";
	char	str3[] = "applepie";
	char	str4[] = "apples";
	int		n = 5;

	printf("Comparing \"%s\" and \"%s\" up to %d characters: %d\n",
		str1, str2, n, ft_strncmp(str1, str2, n));
	printf("Comparing \"%s\" and \"%s\" up to %d characters: %d\n",
		str1, str3, n, ft_strncmp(str1, str3, n));
	printf("Comparing \"%s\" and \"%s\" up to %d characters: %d\n",
		str1, str4, n, ft_strncmp(str1, str4, n));
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char	*str1, *str2;

	str1 = s1;
	str2 = s2;
	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*str1 - *str2);
}
