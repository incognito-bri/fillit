#include "fillit.h"

/*	used to free tetrimino linked list once solution has been found. 
*/

void	solvedfree(t_mino *current)
{
	t_mino	*head;
	t_mino	*temp;

	head = current->head;
	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	exit(0);
}

/* solving algorithm places one piece at a time until all pieces are succesfully placed on board.
if a piece can not be placed we will backtrack to the previous piece and find the next succesful placement for it
in hopes of then being able to place the next piece, once we run out of spaces for either pieces we will continue
to backtrack and repeat the process until we have backtracked all the way to the head of our tetrimino structure
indicating there is no possible solution for the given board size. We will then increase the size of our board
and repeat the process until a solution is reached.
*/

char	*solve(int min_size, t_mino *head)
{
	char	*board;
	t_mino	*temp;
	int		offset;

	offset = 0;
	temp = head;
	board = setup(head, &min_size);
	while (1)
	{
		if (temp == NULL) // end of tetrimino linked list reached, solution found.
			return (board);
		if (temp == temp->head && (!(find_spot(offset, &temp)))) // backtracked all the way to head, no possible solution
				// so we increase board size along with offset, free our previous board and create a bigger one.
		{
			min_size++;
			offset++;
			free(board);
			board = build_board(min_size, head);
		}
		if ((find_spot(offset, &temp))) // if spot is succesfully found for tetrimino we then place on our board.
			temp = place_piece(temp, offset);
		else // nowhere to put current piece so we backtrack to the previous piece and shift over one spot until we can place the next piece.
			temp = remove_piece(temp, offset, board);
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	int			nop;
	t_mino		*current;
	t_mino		*temp;
	int			fd;
	char		*board;

	nop = 1;
	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	current = init_list();
	temp = current;
	readpiece(fd, &temp, &nop);
	close(fd);
	temp = current->head;
	validate(&temp);
	board = solve(nop, temp);
	ft_putendl(board); 
	free(board);
	solvedfree(current);
	return(1);
}
