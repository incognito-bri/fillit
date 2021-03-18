#ifndef FILLIT_H
# define FILLIT_H
# include <math.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct	s_mino // tetrimino linked list structure
{
	int				ap; // number of active pieces
	int				onboard; // boolean whether on board or not
	int				alpha; // designated letter for printing result
	int				offset; // used to keep track of offset in empty space which grows with each increment in board size.
	int				ipat[10]; // stores pattern used to find tetrimino placement on board/
	char			piece[5][5]; // 2d array used to validate and initially store tetriminos.
	char			*lgs; // last spot on board on which piece can be succesfully placed.
	struct s_mino	*next; 
	struct s_mino	*prev;
	struct s_mino	*head;

}				t_mino;

typedef struct	s_fp // used to find valid spot on board for tetriminos.
{
	int				start; // starting point for where to search for a placement.
	int				place; // stores our current index on ipat value within tetrimino structure.
	int				pattern; // stores current value of ipat we are working with.
	int				io; // bool for active piece or empty space.
	int				i; // tracks distance from start on our board.

}				t_fp;

int				readpiece(int fd, t_mino **current, int *nop);
int				write_mino(t_mino **current, char *line, int *ln, int *l);
void			new_mino(t_mino **current, int *nop, int *ln, int *l);
int				check_contacts(int ln, t_mino *current);
t_mino			*append_piece(t_mino *current);
int				validate(t_mino **current);
char			*build_piece(t_mino *current, int size);
t_mino			*init_list();
void			exfree(t_mino	**current);
void			pattern(t_mino **head, int min_size);
char			*solve(int min_size, t_mino *head);
char			*setup(t_mino *head, int *min_size);
char			*build_board(int size, t_mino *head);
int				find_spot(int	offset, t_mino **current);
char			*ft_piecetrim(char *piece);
int				next_best_board(int nop, t_mino *head);
t_mino			*place_piece(t_mino *current, int offset);
t_mino			*remove_piece(t_mino *current, int offset, char *board);
int				smallest_solution(t_mino **current);
int				small_board_check(t_mino *head, int size);

#endif
