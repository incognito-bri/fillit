#include "fillit.h"

/* returns length of one side for the smallest possible square tetriminos will fit into by taking the 
number of pieces and multiplying by 4 */

int		next_best_board(int nop, t_mino *head)
{
	int ap;
	int l;

	l = 2;
	if (nop < 3)
	{
		while ((!small_board_check(head, nop + 1)))
			nop++;
	}
	ap = (nop * 4);
	while (ap > (l * l))
		l++;
	return (l);
}

/* checks for specific edgecase where 1 or 2 tetriminos are used as input
and part of the tetrimino is trimmed when building piece which will later result in error. */

int		small_board_check(t_mino *head, int size)
{
	t_mino	*temp;
	char	*checker;
	int		n;
	int		i;

	i = -1;
	temp = head;
	n = 0;
	while (temp != NULL)
	{
		checker = build_piece(temp, size);
		while (checker[++i] != '\0')
			if (checker[i] == '#')
				n++;
		if (n < 4)
			return (0);
		i = -1;
		n = 0;
		temp = temp->next;
	}
	free(checker);
	return (1);
}

/* each tetrimino structure contains a pointer *lgs (last good spot) for the last spot in which the
tetrimino can be succesfully placed. Because we have not gotten into the solver we are setting lgs 
for each tetrimino as the start of the board so we know from where to start looking for spots 
to place piece.*/

void	assign_board(char *board, t_mino *head)
{
	t_mino *temp;

	temp = head;
	while (temp != NULL)
	{
		temp->lgs = board;
		temp = temp->next;
	}
}

/* using the return of minimum board size we build a board in the form of a 
string array populated with '.' and '\n'. '.'  designates empty space in which tetrimino can be placed.
having a 2d array allows us to use string search like functionality moving forward.	 */

char	*build_board(int size, t_mino *head)
{
	char	*board;
	int		l;
	int		i;

	i = 1;
	l = ((size + 1) * size);
	board = (char *)ft_memalloc(sizeof(char) * (l));
	while (i < l)
	{
		if (i % (size + 1) == 0 && i != 0)
		{
			board[i - 1] = '\n';
			i++;
		}
		board[i - 1] = '.';
		i++;
	}
	board[i - 1] = '\0';
	assign_board(board, head);
	return (board);
}
