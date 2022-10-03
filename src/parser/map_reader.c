#include "../../inc/parser.h"

void update_wh(int *w, int *h, int len)
{
	if (*w < len)
		*w = len;
	(*h)++;
}

void map_reader(t_map *map, int fd)
{
	char *str;
	int  w;
	int  h;
	int  len;

	w = 0;
	h = 0;
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
		update_wh(&w, &h, len);
		ft_deq_insert_rear(map->map_deq, str);
	}
}
