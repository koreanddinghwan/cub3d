#include "../../inc/parser.h"

int check_open(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	return (fd);
}
