/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:02:50 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:02:50 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./local_parser.h"

void	char_check(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && (ft_isdigit(buf[i]) || buf[i] == ','))
		i++;
	if (ft_strlen(buf + i) > 0)
		error_exit("rgb error");
}

void	get_rgb(t_map *map, int id)
{
	char	**sp;
	int		i;
	int		atoi;

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
			map->f_rgb = (map->f_rgb << 8) + atoi;
		else
			map->c_rgb = (map->c_rgb << 8) + atoi;
		i++;
	}
	delete_splited(sp);
	free(map->buffer);
}
