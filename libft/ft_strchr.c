#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	tofind;

	tofind = (char)c;
	if (c == '\0')
	{
		while (*s)
		{
			s++;
		}
		return ((char*)s);
	}
	while (*s)
	{
		if ((char)*s == tofind)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
