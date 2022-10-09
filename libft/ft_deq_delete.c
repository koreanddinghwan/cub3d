/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:42 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:43 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deq_delete(t_deque	*pDeque)
{
	t_dlst	*rtn;

	if (!pDeque)
		exit(1);
	rtn = ft_deq_pop_front(pDeque);
	while (rtn)
	{
		free(rtn->content);
		free(rtn);
		rtn = ft_deq_pop_front(pDeque);
	}
	free(pDeque);
}
