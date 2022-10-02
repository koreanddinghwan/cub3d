#include "ft_deque.h"

t_deque* ft_deq_new(void)
{
	t_deque *rtn = calloc(1, sizeof(t_deque));
	if (!rtn)
		exit(1);
	return (rtn);
}
