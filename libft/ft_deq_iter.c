/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:49 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:50 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deq_front_iter(t_deque *deq, void (*f)(void*))
{
	t_dlst	*cur;

	if (!deq)
		return ;
	if (!f)
		return ;
	cur = deq->pfrontnode;
	while (cur)
	{
		f(cur->content);
		cur = cur->next;
	}
}

void	ft_deq_rear_iter(t_deque *deq, void (*f)(void*))
{
	t_dlst	*cur;

	if (!deq)
		return ;
	if (!f)
		return ;
	cur = deq->prearnode;
	while (cur)
	{
		f(cur->content);
		cur = cur->back;
	}
}
