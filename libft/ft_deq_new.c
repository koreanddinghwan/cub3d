/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:51 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:52 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

t_deque	*ft_deq_new(void)
{
	t_deque	*rtn;

	rtn = calloc(1, sizeof(t_deque));
	if (!rtn)
		exit(1);
	return (rtn);
}
