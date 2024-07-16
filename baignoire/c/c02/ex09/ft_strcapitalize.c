#include <stdio.h>

char		*ft_strcapitalize(char *str);

int	main(void)
{
	char	str1[] = "hello world! this is a test.";
	char	str2[] = "123abc ABC xyz";
	char	str3[] = "";

	printf("Original: %s\n", str1);
	printf("Capitalized: %s\n", ft_strcapitalize(str1));

	printf("Original: %s\n", str2);
	printf("Capitalized: %s\n", ft_strcapitalize(str2));

	printf("Original: \"%s\"\n", str3);
	printf("Capitalized: \"%s\"\n", ft_strcapitalize(str3));
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i,	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (!new_word && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}
