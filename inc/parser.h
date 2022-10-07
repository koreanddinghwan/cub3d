#ifndef PARSER_H
# define PARSER_H

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../minilibx_opengl_20191021/mlx.h"

#include "../libft/libft.h"

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

typedef enum idnt
{
	NO = 0,
	SO,
	WE,
	EA,
	F,
	C,
	MAP,
	END
} e_symbol_id;


typedef struct s_map
{
	char *NO; //
	char *SO;//
	char *WE;//
	char *EA;//
	int F[3]; //floor rgb
	int C[3]; //ceiling rgb
	int **map; //
	int max_map_width;//
	int map_height;//
	e_map view;
	int symbols[6];
	char *buffer;
	t_deque *map_deq;
} t_map;

# define ERROR "ERROR\n"

t_map *parser(char *path);
int map_open(char *path);
void map_reader(t_map *map, int fd);
void map_make(t_map *map);
void map_fill(t_map *map, t_dlst *start);
void map_validation(t_map *map);

void extension_checker(char *path, char *ext);
int check_open(char *path);
void error_exit(char *str);
void delete_splited(char **sp);
/*
 * F 220,100,0
 *
 * C 225,30,0
 * */
void get_img_pointer(t_map *map, int id);
void get_rgb(t_map *map, int id);

/*
 * @tools
 * */
int split_len(char **sp);
#endif
