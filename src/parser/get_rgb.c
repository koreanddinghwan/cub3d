#include "../../inc/parser.h"

/*
 * 1. ,와 숫자로만 이뤄져야하며
 * 2. ,의 개수는 2개.
 * 3. ,로 split하면 길이는 3이어야한다.
 * */

void char_check(char *buf)
{
	int i;

	i = 0;
	while (buf[i] && (ft_isdigit(buf[i]) || buf[i] == ','))
		i++;
	if (ft_strlen(buf + i) > 0)
		error_exit("rgb error");
}

void get_rgb(t_map *map, int id)
{
	char **sp;
	int i;
	int atoi;

	sp = ft_split(map->buffer, ',');
	if (split_len(sp) != 3)
		error_exit("rgb error\n");
	i = 0;
	while (sp[i])
	{
		atoi = ft_atoi(sp[i]);
		if (atoi < 0 || atoi > 255)
			error_exit("atoi error\n");
		if (id == F)
			map->F[i] = atoi;
		else
			map->C[i] = atoi;
		i++;
	}
	delete_splited(sp);
	free(map->buffer);
}
