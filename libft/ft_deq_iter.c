#include "libft.h"

void	ft_deq_front_iter(t_deque *deq, void (*f)(void*))
{
	t_dlst	*cur;

	if (!deq)
		return ;
	if (!f)
		return ;
	cur = deq->pFrontNode;
	while (cur)
	{
		f(cur->content);
		cur = cur->next;
	}
}

void	ft_deq_rear_iter(t_deque *deq, void (*f)(void*))
{
	t_dlst	*cur;

	if (!deq)
		return ;
	if (!f)
		return ;
	cur = deq->pRearNode;
	while (cur)
	{
		f(cur->content);
		cur = cur->back;
	}
}
