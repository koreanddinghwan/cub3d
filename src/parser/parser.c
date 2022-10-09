/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:21 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:22 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./local_parser.h"

void	init_map(t_map **map)
{
	int	i;

	*map = malloc(sizeof(t_map));
	if (!*map)
		error_exit("map alloc error");
	i = 0;
	while (i < 6)
		(*map)->symbols[i++] = 0;
	(*map)->no = NULL;
	(*map)->so = NULL;
	(*map)->we = NULL;
	(*map)->ea = NULL;
	(*map)->f_rgb = 0;
	(*map)->c_rgb = 0;
}

t_map	*parser(char *path)
{
	t_map	*map;

	init_map(&map);
	map_reader(map, map_open(path));
	map_make(map);
	map_validation(map);
	ft_deq_delete(map->map_deq);
	printf("map check OK\n");
	return (map);
}
