#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcc;
	char	*dstc;
	size_t	i;

	i = -1;
	srcc = (char *)src;
	dstc = (char *)dst;
	if (dst != NULL || src != NULL)
	{
		if (srcc < dstc)
			while ((int)(--len) >= 0)
				*(dstc + len) = *(srcc + len);
		else
			while (++i < len)
				*(dstc + i) = *(srcc + i);
	}
	return (dst);
}
