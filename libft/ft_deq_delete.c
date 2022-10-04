#include "libft.h"

void ft_deq_delete(t_deque* pDeque)
{
	t_dlst *rtn;

	if (!pDeque)
		exit(1);
	rtn = ft_deq_pop_front(pDeque);
	while (rtn)
	{
		free(rtn->content);
		free(rtn);
		rtn = ft_deq_pop_front(pDeque);
	}
	free(pDeque);
}
