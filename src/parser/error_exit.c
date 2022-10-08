#include "../../inc/parser.h"

void	error_exit(char *str)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}
