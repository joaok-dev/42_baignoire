#include <stdio.h>

int		ft_isalnum(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		 || (c >= '0' && c <= '9'));
}

int		ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		ft_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	ft_toupper(char c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

char	ft_tolower(char c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	char	*s;
	int		new_word;

	s = str;
	new_word = 1;
	while (*s)
	{
		if (ft_isalnum(*s))
		{
			if (new_word)
				*s = ft_toupper(*s);
			else
				*s = ft_tolower(*s);
			new_word = 0;
		}
		else
			new_word = 1;
		s++;
	}
	return (str);
}

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


