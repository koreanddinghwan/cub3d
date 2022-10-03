#ifndef GLOBAL_H
# define GLOBAL_H

#include "../libft/libft.h"

typedef struct s_map
{
	void *NO;
	void *SO;
	void *WE;
	void *EA;
	int F[3];
	int C[3];
	int **map;
	t_deque *map_deq;
	int max_map_width;
	int map_height;
} t_map;

# define WIDTH 640
# define HEIGHT 480
# define ERROR "ERROR\n"

#endif
