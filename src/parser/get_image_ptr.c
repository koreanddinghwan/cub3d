#include "../../inc/parser.h"

void get_img_pointer(t_map *map, int id, void *mlx_ptr)
{
	int width;
	int height;

	extension_checker(map->buffer, ".xpm");
	if (id == NO)
		map->NO = mlx_xpm_file_to_image(mlx_ptr, map->buffer, &width, &height);
	else if (id == SO)
		map->SO = mlx_xpm_file_to_image(mlx_ptr, map->buffer, &width, &height);
	else if (id == WE)
		map->WE = mlx_xpm_file_to_image(mlx_ptr, map->buffer, &width, &height);
	else if (id == EA)
		map->EA = mlx_xpm_file_to_image(mlx_ptr, map->buffer, &width, &height);
	free(map->buffer);
}
