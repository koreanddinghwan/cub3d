/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:53 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:54 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

t_dlst	*ft_deq_peek_front(t_deque *pDeque)
{
	if (!pDeque)
		exit(1);
	if (pDeque->currentelementcount == 0)
		return (NULL);
	else
		return (pDeque->pfrontnode);
}

t_dlst	*ft_deq_peek_rear(t_deque *pDeque)
{
	if (!pDeque)
		exit(1);
	if (pDeque->currentelementcount == 0)
		return (NULL);
	else
		return (pDeque->prearnode);
}
