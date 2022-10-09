/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:04 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:05 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./local_parser.h"

int	map_open(char *path)
{
	extension_checker(path, ".cub");
	return (check_open(path));
}
