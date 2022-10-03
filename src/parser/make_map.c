#include "../../inc/parser.h"

/*
 *
	
	NO ./path_to_the_north_texture
	
	SO ./path_to_the_south_texture
	WE ./path_to_the_west_texture
	EA ./path_to_the_east_texture
	F 220,100,0

	C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
 * */

int symbol_identifier(char *str, t_map *map)
{
	char **split;
	int  id;

	split = ft_split(str, 32);
	if (!split)
		error_exit();
	if (ft_strcmp(split[0], "NO") == 0)
		id = NO;
	else if (ft_strcmp(split[0], "SO") == 0)
		id = SO;
	else if (ft_strcmp(split[0], "WE") == 0)
		id = WE;
	else if (ft_strcmp(split[0], "EA") == 0)
		id = EA;
	else if (ft_strcmp(split[0], "F") == 0)
		id = F;
	else if (ft_strcmp(split[0], "C") == 0)
		id = C;
	return (id);
}

void fill_map(t_map *map, int fd)
{
	char *str;
	int  status;
	int id[6];
	int id_index;

	ft_memset(id, 0, 6);
	id_index = 0;
		symbol_identifier(str, map);
		/*
		 * NO, SO 등의 심볼이 다 안채워짐 ==
		 * id가 map인데, status가 6개 미만일때
		 * */
		//check_symbol_error
}
