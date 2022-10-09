/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:44 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:46 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	ft_deq_insert_rear(t_deque	*pDeque, void *c)
{
	t_dlst	*element;

	element = ft_dlst_new(c);
	if (!pDeque)
		exit(1);
	if (ft_deq_is_empty(pDeque) == TRUE)
	{
		pDeque->pfrontnode = element;
		pDeque->prearnode = element;
	}
	else
	{
		pDeque->prearnode->next = element;
		element->back = pDeque->prearnode;
		pDeque->prearnode = element;
	}
	pDeque->currentelementcount++;
	return (TRUE);
}

int	ft_deq_insert_front(t_deque	*pDeque, void *c)
{
	t_dlst	*element;

	element = ft_dlst_new(c);
	if (!pDeque)
		exit(1);
	if (ft_deq_is_empty(pDeque) == TRUE)
	{
		pDeque->pfrontnode = element;
		pDeque->prearnode = element;
	}
	else
	{
		pDeque->pfrontnode->back = element;
		element->next = pDeque->pfrontnode;
		pDeque->pfrontnode = element;
	}
	pDeque->currentelementcount++;
	return (TRUE);
}
