#include "libft.h"
#include <stdio.h>

void *newcontent(char *str)
{
	char *rtn;

	rtn = malloc(50);
	ft_strlcpy(rtn, str, 50);
	return (rtn);
}

void printer(void *c)
{
	printf("%s\n", (char *)c);
}

int main(void)
{
	char *a = "Asdfasdf";
	char *b = "asdfasdf";
	char *c = "asddfsfsdf";

	{
	t_deque *deq = ft_deq_new();

	ft_deq_insert_front(deq, newcontent(a));
	ft_deq_front_iter(deq, printer);

	}
	while (1);
	return (0);
}
