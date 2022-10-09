/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:02:45 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:02:45 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./local_parser.h"

void	extension_checker(char *path, char *ext)
{
	char	*dot;

	dot = ft_strrchr(path, '.');
	if (!dot || ft_strcmp(dot, ext) != 0)
		error_exit("extension check failed\n");
}
