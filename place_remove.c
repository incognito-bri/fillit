#include "fillit.h"

/* place current piece on board with with the help of lgs and offset value, also places on board with alpha value
found inside struct so it is ready to be printed. */

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

/* resets lgs for current piece to begining of board. set current pieces to previous element in linked list
then removes the piece using ipat variable in tetrimino struct as well as offset value. finally we increment lgs for current
tetrimino to begin looking for new possible spot to place.*/

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
