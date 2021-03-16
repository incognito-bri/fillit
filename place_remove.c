#include "fillit.h"

t_mino	*place_piece(t_mino *current, int offset)
{
	int	i;
	int c;
	int	io;
	int pattern;

	i = -1;
	c = 0;
	io = -1;
	while (current->ipat[++i] != 0)
	{
		io *= -1;
		pattern = current->ipat[i];
		if (io == -1)
			pattern += offset;
		while (pattern--)
		{
			if (io == 1)
				current->lgs[c] = current->alpha;
			c++;
		}
	}
	return (current->next);
}

t_mino	*remove_piece(t_mino *current, int offset, char *board)
{
	int i;
	int c;
	int io;
	int	pattern;

	i = -1;
	c = 0;
	io = -1;
	current->lgs = board;
	current = current->prev;
	while (current->ipat[++i] != 0)
	{
		io *= -1;
		pattern = current->ipat[i];
		if (io == -1)
			pattern += offset;
		while (pattern--)
		{
			if (io == 1)
				current->lgs[c] = '.';
			c++;
		}
	}
	current->lgs++;
	return (current);
}
