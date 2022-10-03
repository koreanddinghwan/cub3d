#include "../../inc/parser.h"

/*
 *
	
	NO ./path_to_the_north_texture
	
	SO ./path_to_the_south_texture
	WE ./path_to_the_west_texture
	EA ./path_to_the_east_texture
	F 220,100,0

	C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
 * */

int symbol_identifier(char *str, t_map *map)
{
	char **split;
	int  id;

	split = ft_split(str, ' ');
	if (!split)
		error_exit();
	if (ft_strcmp(split[0], "NO") == 0)
		id = NO;
	else if (ft_strcmp(split[0], "SO") == 0)
		id = SO;
	else if (ft_strcmp(split[0], "WE") == 0)
		id = WE;
	else if (ft_strcmp(split[0], "EA") == 0)
		id = EA;
	else if (ft_strcmp(split[0], "F") == 0)
		id = F;
	else if (ft_strcmp(split[0], "C") == 0)
		id = C;
	else
		id = MAP;
	map->buffer = ft_strdup(split[1]);
	delete_splited(split);
	return (id);
}

void charlen_check(char **sp)
{
	int i;
	int j;

	i = 0;
	while (sp[i])
	{
		j = 0;
		while (sp[i][j])
		{
			if (ft_isalpha(sp[i][j]))
				error_exit();
			j++;
		}
		i++;
	}
	if (i != 3)
		error_exit();
}

void get_rgb(t_map *map, int id)
{
	char **sp;
	int i;
	int atoi;

	sp = ft_split(map->buffer, ',');
	charlen_check(sp);
	i = 0;
	while (sp[i])
	{
		atoi = ft_atoi(sp[i]);
		if (atoi < 0 || atoi > 255)
			error_exit();
		if (id == F)
			map->F[i] = atoi;
		else
			map->C[i] = atoi;
		i++;
	}
	delete_splited(sp);
}

void get_img_pointer(t_map *map, int id, void *mlx_ptr)
{
	int width;
	int height;

	if (id == NO)
		map->NO = mlx_xpm_file_to_image(mlx_ptr, map->buffer, &width, &height);
	else if (id == SO)
		map->SO = mlx_xpm_file_to_image(mlx_ptr, map->buffer, &width, &height);
	else if (id == WE)
		map->SO = mlx_xpm_file_to_image(mlx_ptr, map->buffer, &width, &height);
	else if (id == EA)
		map->SO = mlx_xpm_file_to_image(mlx_ptr, map->buffer, &width, &height);
	free(map->buffer);
}

void symbol_update(t_map *map, int id, void *mlx_ptr)
{
	if (id == MAP)
		return ;
	map->symbols[id]++;
	if (map->symbols[id] == 2)
		error_exit();
	if (id >= 0 && id <= 3)
		get_img_pointer(map, id, mlx_ptr);
	else
		get_rgb(map, id);
}

void symbol_missing(t_map *map)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (map->symbols[i++] == 0)
			error_exit();
	}
}

void get_map_data(t_map *map, int fd, void *mlx_ptr)
{
	int  id;
	t_dlst *node;

	node = map->map_deq->pFrontNode;
	/*
	 * symbol update
	 * */
	while (node)
	{
		id = symbol_identifier(node->content, map);
		//map->buffer에 split된 다음 값 가진 상태
		symbol_update(map, id, mlx_ptr);
		if (id == MAP)
			break ;
		node = node->next;
	}
	symbol_missing(map);
}
