#include "fillit.h"

void	increment(int *n, char **s)
{
	*n += 1;
	*s += 1;
}

void	singlepattern(t_mino **temp, int size)
{
	char	*piece;
	char	*start;
	int		i;
	int		s;

	s = 0;
	piece = build_piece((*temp), size);
	start = piece;
	while (piece != '\0')
	{
		i = 0;
		while (*piece == '#' && *piece != '\0')
			increment(&i, &piece);
		(*temp)->ipat[s] = i;
		s++;
		i = 0;
		if (*piece == '\0')
			break ;
		while (*piece != '#' && *piece != '\0')
			increment(&i, &piece);
		(*temp)->ipat[s] = i;
		s++;
	}
	free(start);
}

void	pattern(t_mino **head, int size)
{
	t_mino	*temp;

	temp = (*head);
	while (temp != NULL)
	{
		singlepattern(&temp, size);
		temp = temp->next;
	}
}

char	*setup(t_mino *head, int *min_size)
{
	char	*board;
	t_mino	*temp;

	temp = head;
	*min_size = next_best_board(*min_size, head);
	board = build_board(*min_size, head);
	pattern(&head, *min_size);
	return (board);
}
