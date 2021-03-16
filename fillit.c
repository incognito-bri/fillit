#include "fillit.h"

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
		if (temp == NULL)
			return (board);
		if (temp == temp->head && (!(find_spot(offset, &temp))))
		{
			min_size++;
			offset++;
			free(board);
			board = build_board(min_size, head);
		}
		if ((find_spot(offset, &temp)))
			temp = place_piece(temp, offset);
		else
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
