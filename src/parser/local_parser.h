/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:02:53 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:02:54 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCAL_PARSER_H
# define LOCAL_PARSER_H

# include "../../inc/common.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

int		map_open(char *path);
void	map_reader(t_map *map, int fd);
void	map_make(t_map *map);
void	map_fill(t_map *map, t_dlst *start);
void	map_validation(t_map *map);
void	extension_checker(char *path, char *ext);
int		check_open(char *path);
void	error_exit(char *str);
void	delete_splited(char **sp);
void	get_img_pointer(t_map *map, int id);
void	get_rgb(t_map *map, int id);
int		split_len(char **sp);

#endif
