#include "fillit.h"

char	*ft_piecetrim(char *piece)
{
	int		b;
	int		e;
	int		i;
	char	*str;

	b = 0;
	i = 0;
	while (piece[b] == '.' || piece[b] == '\n')
		b++;
	e = ft_strlen(piece) - 1;
	while (piece[e] == '.' || piece[e] == '\n')
		e--;
	if (!(str = (char *)malloc(sizeof(char) * (e - b + 2))))
		return (NULL);
	while (i < e - b + 1)
	{
		str[i] = piece[i + b];
		i++;
	}
	str[i] = '\0';
	free(piece);
	return (str);
}

int		find_copy_s(t_mino *current, int *ln, int *lp)
{
	*ln = 0;
	*lp = 0;
	while (!(ft_strstr(current->piece[*ln], "#")))
		*ln += 1;
	while (current->piece[*ln][*lp] != '#' &&
		current->piece[*ln + 1][*lp] != '#' &&
		current->piece[*ln + 2][*lp] != '#' &&
		current->piece[*ln + 3][*lp] != '#')
		*lp += 1;
	return (0);
}

void	array_to_string(t_mino *current, int ln, int lp, char *piece)
{
	int	a;
	int	rp;

	a = 0;
	rp = 0;
	while (ln < 4)
	{
		while ((current->piece[ln] + lp)[a] != '\0' && (current->piece[ln] +
		lp)[a] != '\n' && piece[rp] != '\n' && piece[rp] != '\0')
		{
			piece[rp] = (current->piece[ln] + lp)[a];
			a += 1;
			rp++;
		}
		while (piece[rp] != '\n' && piece[rp] != '\0')
			rp++;
		a = 0;
		rp++;
		ln++;
	}
}

char	*build_piece(t_mino *current, int size)
{
	char	*piece;
	int		ln;
	int		lp;
	int		rp;

	rp = size;
	piece = (char *)ft_memalloc(sizeof(char) * ((size + 1) * size));
	ft_memset(piece, '.', ((size + 1) * size));
	piece[((size * size) + (size - 1))] = '\0';
	while (rp < (((size * size) + (size - 1))))
	{
		piece[rp] = '\n';
		rp += (size + 1);
	}
	find_copy_s(current, &ln, &lp);
	array_to_string(current, ln, lp, piece);
	piece = ft_piecetrim(piece);
	return (piece);
}
