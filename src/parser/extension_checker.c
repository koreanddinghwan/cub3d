#include "../../inc/parser.h"

void extension_checker(char *path, char *ext)
{
	char *dot;

	dot = ft_strrchr(path, '.');
	printf("extension check : %s, %s\n",path, dot);
	if (!dot || ft_strcmp(dot, ext) != 0)
		error_exit("extension check failed\n");
}
