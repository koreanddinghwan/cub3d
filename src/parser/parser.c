#include "../../inc/parser.h"

int main(int ac, char **av)
{
	//t_game game?

	if (ac != 1)
		return (1);

}

void init_map(t_map **map)
{
	int i;

	i = 0;
	*map = malloc(sizeof(t_map));
	if (!*map)
		error_exit();
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
	int fd;
	t_map *map;

	init_map(&map);
	extension_checker(path, "cub");
	fd = check_open(path);
	map_reader(map, fd);
	//deque의 문자열 하나씩 popFront해나가며 t_map 채우기
	return (map);
}
