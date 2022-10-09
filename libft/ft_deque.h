/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:56 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:57 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include "libft.h"

/*
 * implemented using ft_dlst interface
 *
 * !!!---!!!
 * insertFrontLD, insertRearLD use pointer of content;
 * c is heap allocated data
 * 
 * !!!---!!!
 * popFrontLD, popRearLD return last node of deque(t_dlst node);
 * 		so need to free content after use;
 *
 * 
 * void ft_deq_delete(t_deque* pDeque);
 *int ft_deq_insert_rear(t_deque* pDeque, void *c);
 *int ft_deq_insert_front(t_deque* pDeque, void *c);
 *int ft_deq_is_empty(t_deque* pDeque);
 *t_deque* ft_deq_new(void);
 *t_dlst* ft_deq_peek_front(t_deque* pDeque);
 *t_dlst* ft_deq_peek_rear(t_deque* pDeque);
 *t_dlst* ft_deq_pop_front(t_deque* pDeque);
 *t_dlst* ft_deq_pop_rear(t_deque* pDeque);
* void ft_deq_iter();
 * */

#endif
