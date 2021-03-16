#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*tsrc;
	char	*tdst;

	i = 0;
	tsrc = (char *)src;
	tdst = (char *)dst;
	if (!(dst == 0 && src == 0))
	{
		while (n > 0)
		{
			tdst[i] = tsrc[i];
			n--;
			i++;
		}
	}
	return (dst);
}
