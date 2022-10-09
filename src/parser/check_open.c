/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:02:37 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:02:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./local_parser.h"

int	check_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit("open error");
	return (fd);
}
