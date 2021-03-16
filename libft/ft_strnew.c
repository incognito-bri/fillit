#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	return (str);
}
