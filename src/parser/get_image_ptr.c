#include "./local_parser.h"

void	get_img_pointer(t_map *map, int id)
{
	extension_checker(map->buffer, ".xpm");
	if (id == NO)
		map->no = ft_strdup(map->buffer);
	else if (id == SO)
		map->so = ft_strdup(map->buffer);
	else if (id == WE)
		map->we = ft_strdup(map->buffer);
	else if (id == EA)
		map->ea = ft_strdup(map->buffer);
	free(map->buffer);
}
