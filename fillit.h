#ifndef FILLIT_H
# define FILLIT_H
# include <math.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct	s_mino
{
	int				ap;
	int				onboard;
	int				alpha;
	int				offset;
	int				ipat[10];
	char			piece[5][5];
	char			*lgs;
	struct s_mino	*next;
	struct s_mino	*prev;
	struct s_mino	*head;

}				t_mino;

typedef struct	s_fp
{
	int				start;
	int				place;
	int				pattern;
	int				io;
	int				i;

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
