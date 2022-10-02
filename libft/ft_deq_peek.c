#include "ft_deque.h"

t_dlst* ft_deq_peek_front(t_deque* pDeque)
{
	if (!pDeque)
		exit(1);
	if (pDeque->currentElementCount == 0)
		return (NULL);
	else
		return (pDeque->pFrontNode);
}

t_dlst* ft_deq_peek_rear(t_deque* pDeque)
{
	if (!pDeque)
		exit(1);
	if (pDeque->currentElementCount == 0)
		return (NULL);
	else
		return (pDeque->pRearNode);
}
