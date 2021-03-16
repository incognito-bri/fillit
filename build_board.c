#include "fillit.h"

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
