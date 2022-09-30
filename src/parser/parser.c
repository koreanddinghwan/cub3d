#include "../../inc/parser.h"

int main(int ac, char **av)
{
	//t_game game?

	if (ac != 1)
		return (1);

}

int parser(char *path, t_map *map)
{
	int fd;

	//.cub extension_checker
	extension_checker(path, "cub");
	//.cub file open checker
	fd = check_open(path);
	fill_map(map, fd);
	return (TRUE);
}
