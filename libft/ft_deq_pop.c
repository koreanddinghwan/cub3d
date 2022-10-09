/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:55 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:56 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

t_dlst	*ft_deq_pop_front(t_deque *pDeque)
{
	t_dlst	*rtn;

	if (!pDeque)
		exit(1);
	if (pDeque->currentelementcount == 0)
		return (NULL);
	rtn = pDeque->pfrontnode;
	pDeque->pfrontnode = pDeque->pfrontnode->next;
	if (pDeque->pfrontnode)
		pDeque->pfrontnode->back = NULL;
	if (pDeque->currentelementcount == 1)
		pDeque->prearnode = NULL;
	rtn->next = NULL;
	pDeque->currentelementcount--;
	return (rtn);
}

t_dlst	*ft_deq_pop_rear(t_deque *pDeque)
{
	t_dlst	*rtn;

	if (!pDeque)
		exit(1);
	if (pDeque->currentelementcount == 0)
		return (NULL);
	rtn = pDeque->prearnode;
	pDeque->prearnode = pDeque->prearnode->back;
	if (pDeque->prearnode)
		pDeque->prearnode->next = NULL;
	if (pDeque->currentelementcount == 1)
		pDeque->pfrontnode = NULL;
	rtn->back = NULL;
	pDeque->currentelementcount--;
	return (rtn);
}
