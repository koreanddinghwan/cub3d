/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:00 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./local_parser.h"

int	map_converter(char c)
{
	if (ft_isdigit(c) && (c - 48 <= 1))
		return (c - 48);
	else if (c == ' ')
		return (BLANK);
	else if (c == 'N')
		return (PLAYER_N);
	else if (c == 'S')
		return (PLAYER_S);
	else if (c == 'W')
		return (PLAYER_W);
	else if (c == 'E')
		return (PLAYER_E);
	else
		error_exit("Unknown Map Param\n");
	return (FALSE);
}

void	fill(t_map *map, t_dlst *node)
{
	char	*str;
	int		i;
	int		j;

	str = node->content;
	i = 0;
	while (node)
	{
		str = node->content;
		j = 0;
		while (str[j])
		{
			map->map[i][j] = map_converter(str[j]);
			j++;
		}
		while (j < map->max_map_width)
		{
			map->map[i][j] = BLANK;
			j++;
		}
		i++;
		node = node->next;
	}
}

void	map_alloc(t_map *map)
{
	int	i;

	i = 0;
	map->map = ft_calloc(sizeof(int *), map->map_height);
	if (!map->map)
		error_exit("map alloc error");
	while (i < map->map_height)
	{
		map->map[i] = ft_calloc(sizeof(int), map->max_map_width);
		if (!(map->map[i]))
			error_exit("map alloc error");
		i++;
	}
}

void	map_fill(t_map *map, t_dlst *start)
{
	t_size	w;
	t_size	h;
	t_dlst	*node;

	w = 0;
	h = 0;
	node = start;
	while (node)
	{
		if (w < ft_strlen(node->content))
			w = ft_strlen(node->content);
		h++;
		node = node->next;
	}
	map->max_map_width = w;
	map->map_height = h;
	map_alloc(map);
	fill(map, start);
}
