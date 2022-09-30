#include "./libft/libft.h"

int extension_checker(char *path, char *ext)
{
	char *dot;

	dot = ft_strrchr(path, '.');
	if (!dot)
		return (FALSE);
	if (ft_strcmp(dot, ext) != 0)
		return (FALSE);
	return (TRUE);
}
