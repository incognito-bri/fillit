#include "libft.h"

t_darray	*ft_darr_append_char(t_darray *darr, char c)
{
	if (darr == NULL)
		return (NULL);
	if (darr->index == (darr->size - 1))
		if (!(ft_water_array(darr)))
			return (NULL);
	darr->str[darr->index] = c;
	darr->index++;
	return (darr);
}
