#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*tmp;

	tmp = dest;
	while (n--)
		*tmp++ = *src++;
	return (dest);
}
