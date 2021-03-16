#include "libft.h"
#include <stdlib.h>

t_darray	*ft_water_array(t_darray *darr)
{
	char	*biggerarray;

	if (!(biggerarray = (char *)ft_memalloc(sizeof(char) * (darr->size * 2))))
		return (NULL);
	ft_memset(biggerarray, '\0', (darr->size * 2));
	ft_memcpy(biggerarray, darr->str, (darr->size - 1));
	free(darr->str);
	darr->str = biggerarray;
	darr->size = (darr->size * 2);
	return (darr);
}
