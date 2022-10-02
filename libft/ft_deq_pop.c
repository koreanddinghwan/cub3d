#include "ft_deque.h"

t_dlst* ft_deq_pop_front(t_deque* pDeque)
{
	t_dlst *rtn;

	if (!pDeque)
		exit(1);
	if (pDeque->currentElementCount == 0)
		return (NULL);
	rtn  = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->next;
	if (pDeque->pFrontNode)
		pDeque->pFrontNode->back = NULL;
	if (pDeque->currentElementCount == 1)
		pDeque->pRearNode = NULL;
	rtn->next = NULL;
	pDeque->currentElementCount--;
	return (rtn);
}

t_dlst* ft_deq_pop_rear(t_deque* pDeque)
{
	t_dlst *rtn;

	if (!pDeque)
		exit(1);
	if (pDeque->currentElementCount == 0)
		return (NULL);
	rtn  = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->back;
	if (pDeque->pRearNode)
		pDeque->pRearNode->next = NULL;
	if (pDeque->currentElementCount == 1)
		pDeque->pFrontNode = NULL;
	rtn->back = NULL;
	pDeque->currentElementCount--;
	return (rtn);
}
