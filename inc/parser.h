#ifndef PARSER_H
# define PARSER_H

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "global.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

typedef enum idnt
{
	EMPTY = 0,
	NO,
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
void fill_map(t_map *map, int fd);
void error_exit(void);
void map_reader(t_map *map, int fd);

#endif
