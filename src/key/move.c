/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:19:07 by gyumpark          #+#    #+#             */
/*   Updated: 2022/10/11 13:19:08 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_game *game)
{
	if (!game->map->map[(int)(game->vector.p_posx + game->vector.p_dirx * \
				game->vector.p_speed)][(int)(game->vector.p_posy)])
		game->vector.p_posx += game->vector.p_dirx * game->vector.p_speed;
	if (!game->map->map[(int)(game->vector.p_posx)][(int)(game->vector.p_posy \
				+ game->vector.p_diry * game->vector.p_speed)])
		game->vector.p_posy += game->vector.p_diry * game->vector.p_speed;
}

void	move_s(t_game *game)
{
	if (!game->map->map[(int)(game->vector.p_posx - game->vector.p_dirx * \
				game->vector.p_speed)][(int)(game->vector.p_posy)])
		game->vector.p_posx -= game->vector.p_dirx * game->vector.p_speed;
	if (!game->map->map[(int)(game->vector.p_posx)][(int)(game->vector.p_posy \
				- game->vector.p_diry * game->vector.p_speed)])
		game->vector.p_posy -= game->vector.p_diry * game->vector.p_speed;
}

void	move_a(t_game *game)
{
	if (!game->map->map[(int)(game->vector.p_posx + game->vector.p_dirx * \
	cos(M_PI_2) * game->vector.p_speed - game->vector.p_diry * sin(M_PI_2) * \
	game->vector.p_speed)][(int)(game->vector.p_posy)])
		game->vector.p_posx += game->vector.p_dirx * cos(M_PI_2) * \
	game->vector.p_speed - game->vector.p_diry * sin(M_PI_2) * \
	game->vector.p_speed;
	if (!game->map->map[(int)(game->vector.p_posx)][(int)(game->vector.p_posy + \
	game->vector.p_dirx * sin(M_PI_2) * game->vector.p_speed + \
	game->vector.p_diry * cos(M_PI_2) * game->vector.p_speed)])
		game->vector.p_posy += game->vector.p_dirx * sin(M_PI_2) * \
	game->vector.p_speed + game->vector.p_diry * cos(M_PI_2) * \
	game->vector.p_speed;
}

void	move_d(t_game *game)
{
	if (!game->map->map[(int)(game->vector.p_posx + game->vector.p_dirx * \
	cos(-M_PI_2) * game->vector.p_speed - game->vector.p_diry * sin(-M_PI_2) * \
	game->vector.p_speed)][(int)(game->vector.p_posy)])
		game->vector.p_posx += game->vector.p_dirx * cos(-M_PI_2) * \
		game->vector.p_speed - game->vector.p_diry * sin(-M_PI_2) * \
		game->vector.p_speed;
	if (!game->map->map[(int)(game->vector.p_posx)][(int)(game->vector.p_posy + \
	game->vector.p_dirx * sin(-M_PI_2) * game->vector.p_speed + \
	game->vector.p_diry * cos(-M_PI_2) * game->vector.p_speed)])
		game->vector.p_posy += game->vector.p_dirx * sin(-M_PI_2) * \
		game->vector.p_speed + game->vector.p_diry * cos(-M_PI_2) * \
		game->vector.p_speed;
}
