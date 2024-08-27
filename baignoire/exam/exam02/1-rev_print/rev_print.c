#include <unistd.h>

char	*ft_rev_print(char *str)
{
	char	*start;
	char	*end;
	char	tmp;

	start = str;
	end = str;
	while (*end)
		end++;
	end--;
	while (start < end)
	{
		tmp = *start;
		*start++ = *end;
		*end-- = tmp;
	}
	start = str;
	while (*start)
	{
		write(1, start, 1);
		start++;
	}
	write(1, "\n", 1);
	return (str);
}
