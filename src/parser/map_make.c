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

void ignore_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

int symbol_identifier(char *str, t_map *map)
{
	int  id;

	ignore_spaces(&str);
	if (ft_strncmp(str, "NO", 2) == 0)
		id = NO;
	else if (ft_strncmp(str, "SO", 2) == 0)
		id = SO;
	else if (ft_strncmp(str, "WE", 2) == 0)
		id = WE;
	else if (ft_strncmp(str, "EA", 2) == 0)
		id = EA;
	else if (ft_strncmp(str, "F", 1) == 0)
		id = F;
	else if (ft_strncmp(str, "C", 1) == 0)
		id = C;
	else
		id = MAP;
	if (id >= NO && id <= EA)
		str += 2;
	else if (id == F || id == C)
		str += 1;
	ignore_spaces(&str);
	map->buffer = ft_strdup(str);
	return (id);
}

void symbol_update(t_map *map, int id)
{
	if (id == MAP)
		return ;
	map->symbols[id]++;
	if (map->symbols[id] == 2)
		error_exit("dup symbol\n");
	if (id >= 0 && id <= 3)
		get_img_pointer(map, id);
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
			error_exit("missing symbol\n");
	}
}

void map_make(t_map *map)
{
	int  id;
	t_dlst *node;

	node = map->map_deq->pFrontNode;
	while (1)
	{
		id = symbol_identifier(node->content, map);
		symbol_update(map, id);
		if (id == MAP)
			break ;
		node = node->next;
	}
	symbol_missing(map);
	map_fill(map, node);
}
