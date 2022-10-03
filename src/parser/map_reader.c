#include "../../inc/parser.h"

void map_reader(t_map *map, int fd)
{
	char *str;
	int  len;

	map->map_deq = ft_deq_new();
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			return ;
		len = ft_strlen(str);
		if (len == 0)
		{
			free(str);
			continue;
		}
		ft_deq_insert_rear(map->map_deq, str);
	}
}
