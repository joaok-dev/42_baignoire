#include <stdlib.h>

static int	ft_numlen(int nbr)
{
	int	len;

	len = (nbr <= 0);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	long	n;

	n = nbr;
	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str += len;
	*str = '\0';
	if (n < 0)
		n = -n;
	while (len--)
	{
		*--str = (n % 10) + '0';
		n /= 10;
	}
	if (nbr < 0)
		*--str = '-';
	return (str);
}
