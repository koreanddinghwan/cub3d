#include "ft_deque.h"

int ft_deq_insert_rear(t_deque* pDeque, void *c)
{
	t_dlst *element;

	element = ft_dlst_new(c);
	if (!pDeque)
		exit(1);
	if (ft_deq_is_empty(pDeque) == TRUE)
	{
		pDeque->pFrontNode = element;
		pDeque->pRearNode = element;
	}
	else
	{
		pDeque->pRearNode->next = element;
		element->back = pDeque->pRearNode;
		pDeque->pRearNode = element;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int ft_deq_insert_front(t_deque* pDeque, void *c)
{
	t_dlst *element;

	element = ft_dlst_new(c);
	if (!pDeque)
		exit(1);
	if (ft_deq_is_empty(pDeque) == TRUE)
	{
		pDeque->pFrontNode = element; 
		pDeque->pRearNode = element;  
	} 
	else
	{
		pDeque->pFrontNode->back = element; 
		element->next = pDeque->pFrontNode; 
		pDeque->pFrontNode = element; 
	} 
	pDeque->currentElementCount++;
	return (TRUE);
}
