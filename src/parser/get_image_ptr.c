#include "../../inc/parser.h"

void get_img_pointer(t_map *map, int id)
{
	extension_checker(map->buffer, ".xpm");
	if (id == NO)
		map->NO = ft_strdup(map->buffer);
	else if (id == SO)
		map->SO = ft_strdup(map->buffer);
	else if (id == WE)
		map->WE = ft_strdup(map->buffer);
	else if (id == EA)
		map->EA = ft_strdup(map->buffer);
	free(map->buffer);
}
