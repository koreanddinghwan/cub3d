#include "../../inc/parser.h"

void intprinter(int *t)
{
	for (int i = 0; i < 3; i++)
		printf("%d ", t[i]);
	printf("\n");
}

void mapPrinter(t_map *map)
{
	printf("NO : %p\n", map->NO);
	printf("SO : %p\n", map->SO);
	printf("EA : %p\n", map->EA);
	printf("WE : %p\n", map->WE);
	printf("F: ");
	intprinter(map->F);
	printf("C: ");
	intprinter(map->C);
	printf("map:\n");
	for (int i = 0; i < map->map_height; i++)
	{
		for (int j = 0;  j < map->max_map_width; j++)
		{
			if (map->map[i][j] == 2)
				printf(" ");
			else
				printf("%d", map->map[i][j]);
		}
		printf("\n");
	}
}

int main(int ac, char **av)
{
	//t_game game?

	if (ac != 2)
		return (1);
	void *mlx = mlx_init();
	t_map *map = parser(av[1], mlx);
	mapPrinter(map);
	return (0);
}

void init_map(t_map **map)
{
	int i;

	i = 0;
	*map = malloc(sizeof(t_map));
	if (!*map)
		error_exit("map alloc error");
	while (i < 3)
		(*map)->F[i++] = -1;
	i = 0;
	while (i < 3)
		(*map)->C[i++] = -1;
	i = 0;
	while (i < 6)
		(*map)->symbols[i++] = 0;
	(*map)->NO = NULL;
	(*map)->SO = NULL;
	(*map)->WE = NULL;
	(*map)->EA = NULL;
}

t_map *parser(char *path, void *mlx_ptr)
{
	t_map *map;

	init_map(&map);
	map_reader(map, map_open(path));
	map_make(map, mlx_ptr);
	map_validation(map);
	ft_deq_delete(map->map_deq);
	while (1);
	printf("map check OK\n");
	return (map);
}
