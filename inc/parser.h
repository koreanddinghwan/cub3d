#ifndef PARSER_H
# define PARSER_H

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "global.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../minilibx_opengl_20191021/mlx.h"

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

t_map *parser(char *path, void *mlx_ptr);
int map_open(char *path);
void map_reader(t_map *map, int fd);
void map_make(t_map *map, void *mlx_ptr);
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
void get_img_pointer(t_map *map, int id, void *mlx_ptr);
void get_rgb(t_map *map, int id);

/*
 * @tools
 * */
int split_len(char **sp);
#endif
