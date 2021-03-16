#include "libft.h"

void	ft_strclr(char *s)
{
	char	*ptr;

	ptr = s;
	while (ptr && *ptr)
		*(ptr++) = '\0';
}
