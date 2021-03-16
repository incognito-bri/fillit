#include "libft.h"
#include <string.h>

int	ft_strnequ(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	return (ft_strncmp(s1, s2, n) ? 0 : 1);
}
