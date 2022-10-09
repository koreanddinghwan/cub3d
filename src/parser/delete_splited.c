/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_splited.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:02:39 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:02:40 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./local_parser.h"

void	delete_splited(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
}
