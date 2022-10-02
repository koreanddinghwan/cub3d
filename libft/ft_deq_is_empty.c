#include "ft_deque.h"

int ft_deq_is_empty(t_deque* pDeque)
{
	if (!pDeque)
		exit(1);
	return (pDeque->currentElementCount == 0);
}
