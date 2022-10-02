#include "linkeddeque.h"
#include <stdlib.h>

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *rtn = calloc(1, sizeof(LinkedDeque));
	if (!rtn)
		exit(ENOMEM);
	return (rtn);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;

	if (!pDeque)
		exit(EFAULT);
	new  = calloc(1, sizeof(DequeNode));
	if (!new)
		exit(ENOMEM);
	memcpy(new, &element, sizeof(DequeNode));
	if (isLinkedDequeEmpty(pDeque) == TRUE)
	{
		pDeque->pFrontNode = new;
		pDeque->pRearNode = new;
	}
	else
	{
		pDeque->pFrontNode->pLLink = new;
		new->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = new;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;

	if (!pDeque)
		exit(EFAULT);
	new  = calloc(1, sizeof(DequeNode));
	if (!new)
		exit(ENOMEM);
	memcpy(new, &element, sizeof(DequeNode));
	if (isLinkedDequeEmpty(pDeque) == TRUE)
	{
		pDeque->pFrontNode = new;
		pDeque->pRearNode = new;
	}
	else
	{
		pDeque->pRearNode->pRLink = new;
		new->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = new;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *rtn;

	if (!pDeque)
		exit(EFAULT);
	if (pDeque->currentElementCount == 0)
		return (NULL);
	rtn  = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	if (pDeque->pFrontNode)
		pDeque->pFrontNode->pLLink = NULL;
	if (pDeque->currentElementCount == 1)
		pDeque->pRearNode = NULL;
	rtn->pRLink = NULL;
	pDeque->currentElementCount--;
	return (rtn);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *rtn;

	if (!pDeque)
		exit(EFAULT);
	if (pDeque->currentElementCount == 0)
		return (NULL);
	rtn  = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	if (pDeque->pRearNode)
		pDeque->pRearNode->pRLink = NULL;
	if (pDeque->currentElementCount == 1)
		pDeque->pFrontNode = NULL;
	rtn->pLLink = NULL;
	pDeque->currentElementCount--;
	return (rtn);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (!pDeque)
		exit(EFAULT);
	if (pDeque->currentElementCount == 0)
		return (NULL);
	else
		return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (!pDeque)
		exit(EFAULT);
	if (pDeque->currentElementCount == 0)
		return (NULL);
	else
		return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *rtn;

	if (!pDeque)
		exit(EFAULT);
	while ((rtn = deleteFrontLD(pDeque)))
		free(rtn);
	free(pDeque);
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
	if (!pDeque)
		exit(EFAULT);
	else
		return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (!pDeque)
		exit(EFAULT);
	return (pDeque->currentElementCount == 0);
}
