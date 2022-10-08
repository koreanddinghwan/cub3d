#include "./local_parser.h"

void	extension_checker(char *path, char *ext)
{
	char	*dot;

	dot = ft_strrchr(path, '.');
	if (!dot || ft_strcmp(dot, ext) != 0)
		error_exit("extension check failed\n");
}
