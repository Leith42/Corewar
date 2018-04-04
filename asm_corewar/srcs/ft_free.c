#include "asm.h"

void	free_lst(t_lst_op *lst)
{
	t_lst_op *next;

	next = NULL;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}
