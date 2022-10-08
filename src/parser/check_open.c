#include "./local_parser.h"

int	check_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit("open error");
	return (fd);
}
