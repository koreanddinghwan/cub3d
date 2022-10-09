/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:02 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:03 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./local_parser.h"

void	ignore_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

int	symbol_identifier(char *str, t_map *map)
{
	int	id;

	ignore_spaces(&str);
	if (ft_strncmp(str, "NO", 2) == 0)
		id = NO;
	else if (ft_strncmp(str, "SO", 2) == 0)
		id = SO;
	else if (ft_strncmp(str, "WE", 2) == 0)
		id = WE;
	else if (ft_strncmp(str, "EA", 2) == 0)
		id = EA;
	else if (ft_strncmp(str, "F", 1) == 0)
		id = F;
	else if (ft_strncmp(str, "C", 1) == 0)
		id = C;
	else
		id = MAP;
	if (id >= NO && id <= EA)
		str += 2;
	else if (id == F || id == C)
		str += 1;
	ignore_spaces(&str);
	map->buffer = ft_strdup(str);
	return (id);
}

void	symbol_update(t_map *map, int id)
{
	if (id == MAP)
		return ;
	map->symbols[id]++;
	if (map->symbols[id] == 2)
		error_exit("dup symbol\n");
	if (id >= 0 && id <= 3)
		get_img_pointer(map, id);
	else
		get_rgb(map, id);
}

void	symbol_missing(t_map *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (map->symbols[i++] == 0)
			error_exit("missing symbol\n");
	}
}

void	map_make(t_map *map)
{
	int		id;
	t_dlst	*node;

	node = map->map_deq->pfrontnode;
	while (1)
	{
		id = symbol_identifier(node->content, map);
		symbol_update(map, id);
		if (id == MAP)
			break ;
		node = node->next;
	}
	symbol_missing(map);
	map_fill(map, node);
}
