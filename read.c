#include "fillit.h"

int		validate(t_mino **current)
{
	int		ln;
	t_mino	*temp;

	ln = -1;
	temp = (*current);
	while (temp != NULL)
	{
		temp->ap = 0;
		while (++ln < 4)
			check_contacts(ln, temp);
		if (temp->ap != 5 && temp-> ap != 6 && temp->ap != 8)
			exfree(current);
		temp = temp->next;
		ln = -1;
	}
	return (0);
}

int		check_contacts(int ln, t_mino *current)
{
	int	lp;

	lp = -1;
	while (current->piece[ln][++lp] != '\0')
	{
		if (current->piece[ln][lp] == '#')
		{
			if (current->piece[ln][lp - 1] == '#')
				current->ap++;
			if (current->piece[ln][lp + 1] == '#')
				current->ap++;
			if (current->piece[ln - 1][lp] == '#')
				current->ap++;
			if (current->piece[ln + 1][lp] == '#')
				current->ap++;
		}
	}
	return (1);
}

int		readpiece(int fd, t_mino **current, int *nop)
{
	char	*line;
	int		ln;
	int		gnl;
	int		l;

	ln = 0;
	l = 0;
	while ((gnl = get_next_line(fd, &line)))
	{
		if (ft_strlen(line) != 0 && ft_strlen(line) != 4)
			exfree(current);
		if ((ft_strlen(line) == 0))
			new_mino(current, nop, &ln, &l);
		if (ft_strlen(line) == 4)
			write_mino(current, line, &ln, &l);
	}
	return (0);
}

void	new_mino(t_mino **current, int *nop, int *ln, int *l)
{
	if (*l >= 1)
		exfree(current);
	(*current) = append_piece(*current);
	(*nop)++;
	(*ln) = 0;
	(*l)++;
}

int		write_mino(t_mino **current, char *line, int *ln, int *l)
{
	int	lp;

	lp = 0;
	if (*ln >= 4)
		exfree(current);
	while (line[lp] != '\0') //|| line[lp] == '#')
	{
		if (line [lp] != '#' && line[lp] != '.')
			exfree(current);
		if (line[lp] == '#')
		{
			(*current)->ap++;
			if ((*current)->ap > 4)
				exfree(current);
		}
		(*current)->piece[*ln][lp] = line[lp];
		lp++;
	}
	(*ln)++;
	(*l) = 0;
	return (0);
}
