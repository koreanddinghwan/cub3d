#include "../../inc/parser.h"

void error_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}
