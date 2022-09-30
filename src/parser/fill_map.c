#include "../../inc/parser.h"

void fill_map(t_map *map, int fd)
{
	char *str;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			return ;

	}
}


