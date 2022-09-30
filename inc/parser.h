#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
typedef struct s_map
{
	void *NO;
	void *SO;
	void *WE;
	void *EA;
	int F[3];
	int C[3];
	int **map;
} t_map;


void extension_checker(char *path, char *ext);
int check_open(char *path);
void fill_map(t_map *map, int fd);
