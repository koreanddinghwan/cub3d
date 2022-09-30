#include "../../inc/parser.h"

void extension_checker(char *path, char *ext)
{
	char *dot;

	dot = ft_strrchr(path, '.');
	if (!dot || ft_strcmp(dot, ext) != 0)
	{
		ft_putendl_fd("Error\n", 2);
		exit(1);
	}
}
