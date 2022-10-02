#include "ft_deque.h"

void ft_deq_delete(t_deque* pDeque)
{
	t_dlst *rtn;

	if (!pDeque)
		exit(1);
	while ((rtn = ft_deq_pop_front(pDeque)))
	{
		free(rtn->content);
		free(rtn);
	}
	free(pDeque);
}
