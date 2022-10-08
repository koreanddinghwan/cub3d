#include "./local_parser.h"

int	map_open(char *path)
{
	extension_checker(path, ".cub");
	return (check_open(path));
}
