#ifndef GLOBAL_H
# define GLOBAL_H

#include "../libft/libft.h"

typedef struct s_map
{
	void *NO; //
	void *SO;//
	void *WE;//
	void *EA;//
	int F[3]; //floor rgb
	int C[3]; //ceiling rgb
	int **map; //
	int max_map_width;//
	int map_height;//
	int symbols[6];
	char *buffer;
	t_deque *map_deq;
} t_map;

# define WIDTH 640

# define HEIGHT 480

# define ERROR "ERROR\n"

typedef enum e_map_num
{
	ROAD = 0,
	WALL = 1,
	BLANK = 2,
	PLAYER_N = 4,
	PLAYER_S = 5,
	PLAYER_W = 6,
	PLAYER_E = 7
} e_map;

#endif
