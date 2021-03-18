#include "fillit.h"

/* last step in validation repurposes AP variable in tetrimino structure to check for contact points
a contact point is where two active pieces make contact, a valid tetrimino piece will have 5, 6, or 8 
contact points	validate function will iterate through entire tetrimino linked list structure */

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

/* iterates through each element of 2d array in which tetrimino is found and 
adjusts AP variable inside stucture for validaton */

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


/* reads input file and saves each tetrimino piece into a linked list structure
also ensures each line in input file is appropriate length of either 0 or 4 characters for validation	*/


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

/* creates a new tetrimino structure and appends to tail end of linked list 
also keeps track of consecutive empty lines (l) for validation 	*/

void	new_mino(t_mino **current, int *nop, int *ln, int *l)
{
	if (*l >= 1)
		exfree(current);
	(*current) = append_piece(*current);
	(*nop)++;
	(*ln) = 0;
	(*l)++;
}

/* writes each line of a tetrimino piece into the approriate element of a 2d array while adjusting 
AP (active piece) for each # for validation purposes. also adjusts
and keeps track of LN (line number) in tetrimino piece for validation */

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
