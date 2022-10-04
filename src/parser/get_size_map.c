#include "../../inc/parser.h"

void map_fill(t_map *map, t_dlst *node)
{
	char *str;
	int i;
	int j;

	str = node->content;
	i = 0;
	while (node)
	{
		str = node->content;
		j = 0;
		while (str[j])
		{
			map->map[i][j] = str[j];
			j++;
		}
		i++;
		node = node->next;
	}
}

void map_alloc(t_map *map)
{
	int i;

	i = 0;
	map->map = ft_calloc(sizeof(int *), map->map_height);
	if (!map->map)
		error_exit("map alloc error");
	while (i < map->map_height)
	{
		map->map[i] = ft_calloc(sizeof(int), map->max_map_width);
		if (!(map->map[i]))
			error_exit("map alloc error");
		i++;
	}
}

void make_map(t_map *map, t_dlst *start)
{
	int w;
	int h;
	t_dlst *node;

	w = 0;
	h = 0;
	node = start;
	while (node)
	{
		if (w < ft_strlen(node->content))
			w = ft_strlen(node->content);
		h++;
		node = node->next;
	}
	map->max_map_width = w;
	map->map_height = h;
	map_alloc(map);
	map_fill(map, start);
}
