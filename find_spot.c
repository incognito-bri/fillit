#include "fillit.h"

/* reset our params and increments our start value by one */ 

int		reset(t_fp *params)
{
	params->i = 0;
	params->place = -1;
	params->start += 1;
	params->io = -1;
	return (1);
}

/* structure to help us find a spot for our tetrimino within our board.
start element represents the space from our LGS on our board from which to start looking
place element let's us know what index of our ipat variable within tetrimino structure we are working with
IO element is boolean where 1 represents an AP and we are looking for an empty spot on board '.' and 
-1 is empty space which can be populated by other AP from previously placed tetriminos, '.', or '\n'
I represents our distance in int value we have come from Start..
there is also a pattern element which stores the value from tetrimino ipat with which we are working with	*/

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

/* using parameters from our find structure we will iterate through our board in order to find 
the next spot in which we can succesfully place our tetrimino*/

int		find_spot(int offset, t_mino **current)
{
	t_fp	*find;

	find = initparams();
	while ((*current)->lgs[find->start] != '\0')
	{
		find->io *= -1;
		find->pattern = (*current)->ipat[find->place];
		if (find->io == -1)
			find->pattern += offset; // whenver we increase the dimensions of our board the value of offset grows so 
			 						// every time our IO value is -1 we want to increase our pattern value by offset ammount to account for the growth in empty space 
		if ((*current)->ipat[find->place] == 0)
			if (((*current)->lgs = (char *)((*current)->lgs + find->start)))
				return (1); // reached the end of pattern values so we can succesfully place tetrimino start distance from our LGS 
		while (find->pattern--)
		{
			if ((*current)->lgs[find->start + find->i] == '\0')
				return (0); // the end of our board has been reached without space for our tetrimino
			if (find->io == 1 && (*current)->lgs[find->start + find->i] != '.'
			&& (reset(find))) 
				break ; // IO value is 1 which calls for an empty space '.' which we don't have so we reset our parameters, increment start and begin searching again.
			find->i++;
		}
		find->place++; // weve reached the end of our current index within pattern so we move on to the next/
	}
	return (0);
}
