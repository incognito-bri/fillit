#include "fillit.h"

void	exfree(t_mino **current)
{
	t_mino	*head;
	t_mino	*temp;

	head = (*current)->head;
	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	ft_putendl("error");
	exit(0);
}
