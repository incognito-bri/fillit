#include "libft.h"

int	ft_atoi(char *str)
{
	int	res;
	int	negative;

	if (!ft_strcmp(str, "") || !ft_strcmp(str, "-"))
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (!ft_strcmp(str, "-2147483648"))
		return (-2147483648);
	negative = 1;
	res = 0;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * negative);
}
