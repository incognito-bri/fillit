#include "fillit.h"

int		reset(t_fp *params)
{
	params->i = 0;
	params->place = -1;
	params->start += 1;
	params->io = -1;
	return (1);
}

t_fp	*initparams(void)
{
	t_fp	*find;

	if (!(find = (t_fp *)ft_memalloc(sizeof(t_fp))))
		return (NULL);
	find->start = 0;
	find->place = 0;
	find->io = -1;
	find->i = 0;
	return (find);
}

int		find_spot(int offset, t_mino **current)
{
	t_fp	*find;

	find = initparams();
	while ((*current)->lgs[find->start] != '\0')
	{
		find->io *= -1;
		find->pattern = (*current)->ipat[find->place];
		if (find->io == -1)
			find->pattern += offset;
		if ((*current)->ipat[find->place] == 0)
			if (((*current)->lgs = (char *)((*current)->lgs + find->start)))
				return (1);
		while (find->pattern--)
		{
			if ((*current)->lgs[find->start + find->i] == '\0')
				return (0);
			if (find->io == 1 && (*current)->lgs[find->start + find->i] != '.'
			&& (reset(find)))
				break ;
			find->i++;
		}
		find->place++;
	}
	return (0);
}
