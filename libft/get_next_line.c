#include "libft.h"

void	repop_buffer(t_atic *lvar, int fd)
{
	lvar->rstatus = read(fd, lvar->buffer, BUFF_SIZE);
	lvar->index = 0;
}

void	skip_nl(t_atic *lvar)
{
	while (lvar->buffer[lvar->index] == '\n' &&
		lvar->index < lvar->rstatus)
		lvar->index++;
}

int		gnl(t_atic *lvar, t_darray *dnl, int fd, char **line)
{
	while (lvar->buffer[lvar->index] != '\n' && lvar->index < lvar->rstatus)
	{
		ft_darr_append_char(dnl, lvar->buffer[lvar->index]);
		lvar->index++;
	}
	if (lvar->buffer[lvar->index] == '\n')
	{
		*line = dnl->str;
		lvar->index++;
		return (1);
	}
	else
	{
		repop_buffer(lvar, fd);
		if (lvar->rstatus == 0)
		{
			if (dnl->index != 0)
			{
				*line = dnl->str;
				return (1);
			}
			return (0);
		}
		return (lvar->rstatus < 0 ? -1 : gnl(lvar, dnl, fd, line));
	}
}

int		get_next_line(int const fd, char **line)
{
	static	t_atic	lvar = {.index = 0, .rstatus = 0};
	t_darray		*dnl;

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	dnl = ft_init_dynamic_array(20);
	if (lvar.index == lvar.rstatus)
	{
		repop_buffer(&lvar, fd);
		if (lvar.rstatus == 0)
			return (0);
		else if (lvar.rstatus < 0)
			return (-1);
		else
			return (gnl(&lvar, dnl, fd, line));
	}
	else
	{
		return (gnl(&lvar, dnl, fd, line));
	}
}
