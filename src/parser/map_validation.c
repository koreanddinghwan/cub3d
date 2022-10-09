#include "./local_parser.h"

/*
 * @validation map
 * 1. 벽은 막혀있어야한다.
 *
 * ->  map->max_map_width, height의 모든 값은 1 or BLANK여야만 한다.
 * ->  blank의 상하좌우에는 BLANK와 1이어야만한다.
 * */

int	blank_surroundings(t_map *map, int i, int j)
{
	if (map->map[i - 1][j] != BLANK && map->map[i - 1][j] != WALL)
		return (FALSE);
	else if (map->map[i + 1][j] != BLANK && map->map[i + 1][j] != WALL)
		return (FALSE);
	else if (map->map[i][j + 1] != BLANK && map->map[i][j + 1] != WALL)
		return (FALSE);
	else if (map->map[i][j - 1] != BLANK && map->map[i][j - 1] != WALL)
		return (FALSE);
	return (TRUE);
}

void	change_player_viewpos(t_map *map, int i, int j, int *view)
{
	if (*view != 0)
		error_exit("Not Valid Map");
	else
	{
		*view = map->map[i][j];
		map->p_x = i;
		map->p_y = j;
		map->map[i][j] = 0;
	}
}

void	validation(t_map *map, int i, int j, int *view)
{
	if (i == map->map_height || i == 0)
	{
		if (map->map[i][j] != WALL && map->map[i][j] != BLANK)
			error_exit("Not Valid Map");
	}
	else if (j == map->max_map_width || j == 0)
	{
		if (map->map[i][j] != WALL && map->map[i][j] != BLANK)
			error_exit("Not Valid Map");
	}
	else if (map->map[i][j] == BLANK)
	{
		if (i - 1 < 0 || j - 1 < 0 || i + 1 == map->map_height
			|| j + 1 == map->max_map_width)
			return ;
		if (blank_surroundings(map, i, j) == FALSE)
			error_exit("Not Valid Map");
	}
	else if (map->map[i][j] >= 4 && map->map[i][j] <= 7)
		change_player_viewpos(map, i, j, view);
}

void	map_validation(t_map *map)
{
	int	i;
	int	j;
	int	view;

	view = 0;
	if (map->map_height == 1 || map->max_map_width == 1)
		error_exit("map validation error\n");
	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->max_map_width)
			validation(map, i, j++, &view);
		i++;
	}
	if (view == 0)
		error_exit("Not Valid Map");
	map->view = view;
}
