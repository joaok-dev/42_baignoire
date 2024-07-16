#include <stdio.h>

int		ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	str1[] = "apple";
	char	str2[] = "banana";
	char	str3[] = "apple";
	/*char	str4[] = "apricot";*/
	/*char	str5[] = "applepie";*/
	/*char	str6[] = "apple";*/
	/*char	str7[] = "apple";*/
	/*char	str8[] = "apples";*/

	printf("Comparing \"%s\" e \"%s\": %d\n", str1, str2, ft_strcmp(str1, str2));
	printf("Comparing \"%s\" e \"%s\": %d\n", str1, str3, ft_strcmp(str1, str3));
}

int	ft_strcmp(char *s1, char *s2)
{
	char	*str1, *str2;

	str1 = s1;
	str2 = s2;
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
