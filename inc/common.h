/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:03:29 by myukang           #+#    #+#             */
/*   Updated: 2022/10/09 21:03:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx_opengl_20191021/mlx.h"

typedef enum e_map_num
{
	ROAD = 0,
	WALL = 1,
	BLANK = 2,
	PLAYER_N = 4,
	PLAYER_S = 5,
	PLAYER_W = 6,
	PLAYER_E = 7
}	t_map_num;

typedef enum e_symbol_id
{
	NO = 0,
	SO,
	WE,
	EA,
	F,
	C,
	MAP,
	END
}	t_symbol_id;

typedef struct s_map
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f_rgb;
	int			c_rgb;
	int			**map;
	int			max_map_width;
	int			map_height;
	t_map_num	view;
	int			p_x;
	int			p_y;
	int			symbols[6];
	char		*buffer;
	t_deque		*map_deq;
}	t_map;

#endif
