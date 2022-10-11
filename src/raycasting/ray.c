/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:19:26 by gyumpark          #+#    #+#             */
/*   Updated: 2022/10/11 13:30:18 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	t_dda	dda;
	int		x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		game->vector.multiple = (2 * x / (double)(WIN_WIDTH)) - 1;
		game->vector.raydirectionx = game->vector.p_dirx + game->vector.planex \
										* game->vector.multiple;
		game->vector.raydirectiony = game->vector.p_diry + game->vector.planey \
										* game->vector.multiple;
		dda.mapx = (int)(game->vector.p_posx);
		dda.mapy = (int)(game->vector.p_posy);
		dda.deltadistx = fabs(1 / game->vector.raydirectionx);
		dda.deltadisty = fabs(1 / game->vector.raydirectiony);
		game->draw.hit = 0;
		dda_init(game, &dda);
		cal_camera_dir(game, &dda, x);
	}
}

void	dda_init(t_game *game, t_dda *dda)
{
	if (game->vector.raydirectionx < 0)
	{
		dda->stepx = -1;
		dda->sidedistx = (game->vector.p_posx - dda->mapx) * dda->deltadistx;
	}
	else
	{
		dda->stepx = 1;
		dda->sidedistx = (dda->mapx + 1.0 - game->vector.p_posx) * \
							dda->deltadistx;
	}
	if (game->vector.raydirectiony < 0)
	{
		dda->stepy = -1;
		dda->sidedisty = (game->vector.p_posy - dda->mapy) * dda->deltadisty;
	}
	else
	{
		dda->stepy = 1;
		dda->sidedisty = (dda->mapy + 1.0 - game->vector.p_posy) * \
							dda->deltadisty;
	}
	dda_algorithm(game, dda);
}

void	dda_algorithm(t_game *game, t_dda *dda)
{
	while (game->draw.hit == 0)
	{
		if (dda->sidedistx < dda->sidedisty)
		{
			dda->sidedistx += dda->deltadistx;
			dda->mapx += dda->stepx;
			game->draw.side = 0;
		}
		else
		{
			dda->sidedisty += dda->deltadisty;
			dda->mapy += dda->stepy;
			game->draw.side = 1;
		}
		if (game->map->map[dda->mapx][dda->mapy] > 0)
			game->draw.hit = 1;
	}
}

void	cal_camera_dir(t_game *game, t_dda *dda, int x)
{
	if (game->draw.side == 0)
		dda->perpwalldist = (dda->mapx - game->vector.p_posx + \
					(1 - dda->stepx) / 2) / game->vector.raydirectionx;
	else
		dda->perpwalldist = (dda->mapy - game->vector.p_posy + \
					(1 - dda->stepy) / 2) / game->vector.raydirectiony;
	game->draw.draw_height = (int)(WIN_HEIGHT / dda->perpwalldist);
	game->draw.start = (-game->draw.draw_height / 2) + (WIN_HEIGHT / 2);
	if (game->draw.start < 0)
		game->draw.start = 0;
	game->draw.end = (game->draw.draw_height / 2) + (WIN_HEIGHT / 2);
	if (game->draw.end >= WIN_HEIGHT)
		game->draw.end = WIN_HEIGHT - 1;
	if (game->draw.side == 0)
		game->draw.wallx = game->vector.p_posy + dda->perpwalldist * \
							game->vector.raydirectiony;
	else
		game->draw.wallx = game->vector.p_posx + dda->perpwalldist * \
							game->vector.raydirectionx;
	game->draw.wallx = game->draw.wallx - (int)game->draw.wallx;
	cal_tex(game);
	draw(game, x);
}

void	draw(t_game *game, int x)
{
	int	y;

	f_c_draw(game, x);
	y = game->draw.start - 1;
	while (++y < game->draw.end)
	{
		if (game->draw.side == 0)
		{
			if ((game->vector.raydirectiony <= 0 && game->vector.raydirectionx \
						<= 0) || ((game->vector.raydirectiony > 0) \
					&& game->vector.raydirectionx <= 0))
				draw_dir_wall(game, y, x, 0);
			else
				draw_dir_wall(game, y, x, 1);
		}
		else if (game->draw.side == 1 && ((game->vector.raydirectiony <= 0 && \
							game->vector.raydirectionx <= 0) || \
						((game->vector.raydirectiony <= 0) && \
							game->vector.raydirectionx > 0)))
			draw_dir_wall(game, y, x, 2);
		else
			draw_dir_wall(game, y, x, 3);
	}
}
