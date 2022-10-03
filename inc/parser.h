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

void extension_checker(char *path, char *ext);
int check_open(char *path);
void error_exit(void);
void map_reader(t_map *map, int fd);
void delete_splited(char **sp);
t_map *parser(char *path, void *mlx_ptr);
void get_map_data(t_map *map, int fd, void *mlx_ptr);

#endif
