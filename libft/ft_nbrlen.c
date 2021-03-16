#include "libft.h"

int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len += 1;
		nbr *= -1;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
