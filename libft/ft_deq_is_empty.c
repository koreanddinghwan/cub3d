/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_is_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:47 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	ft_deq_is_empty(t_deque	*pDeque)
{
	if (!pDeque)
		exit(1);
	return (pDeque->currentelementcount == 0);
}
