#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*a;
	int		len;
	int		nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	a[len--] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	nbr = n;
	if (n < 0)
	{
		a[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0 && len >= 0)
	{
		a[len--] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	return (a);
}
