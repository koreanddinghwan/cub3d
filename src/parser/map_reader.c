/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:07 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:07 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./local_parser.h"

char	*trim_newline(char *str)
{
	char	*rtn;

	rtn = ft_strtrim(str, "\n");
	free(str);
	return (rtn);
}

void	map_reader(t_map *map, int fd)
{
	char	*str;
	int		len;

	map->map_deq = ft_deq_new();
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			return ;
		str = trim_newline(str);
		len = ft_strlen(str);
		if (len == 0)
		{
			free(str);
			continue ;
		}
		ft_deq_insert_rear(map->map_deq, str);
	}
}
