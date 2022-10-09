#include "cub3d.h"

void	rotate(t_game *game, double speed)
{
	double	o_dirx;
	double	o_planex;

	o_dirx = game->vector.p_dirx;
	o_planex = game->vector.planex;
	game->vector.p_dirx = game->vector.p_dirx * cos(speed) - \
							game->vector.p_diry * sin(speed);
	game->vector.p_diry = o_dirx * sin(speed) + \
							game->vector.p_diry * cos(speed);
	game->vector.planex = game->vector.planex * cos(speed) - \
							game->vector.planey * sin(speed);
	game->vector.planey = o_planex * sin(speed) + \
							game->vector.planey * cos(speed);
}

void	draw_dir_wall(t_game *game, int y, int x, int index)
{
	game->draw.texy = (int)game->draw.texpos & (tex_size - 1);
	game->draw.texpos += game->draw.step;
	game->draw.win_buf[y][x] = game->wall[index][tex_size * \
								game->draw.texy + game->draw.texx];
}

void	f_c_draw(t_game *game, int x)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		game->draw.win_buf[y][x] = game->map->f_rgb;
		game->draw.win_buf[WIN_HEIGHT - y - 1][x] = game->map->c_rgb;
	}
}

void	cal_tex(t_game *game)
{
	game->draw.texx = (int)(game->draw.wallx * (double)tex_size);
	if (game->draw.side == 0 && game->vector.raydirectionx > 0)
		game->draw.texx = tex_size - game->draw.texx - 1;
	if (game->draw.side == 1 && game->vector.raydirectiony < 0)
		game->draw.texx = tex_size - game->draw.texx - 1;
	game->draw.step = 1.0 * tex_size / game->draw.draw_height;
	game->draw.texpos = (game->draw.start - WIN_HEIGHT / 2 + \
				game->draw.draw_height / 2) * game->draw.step;
}

void	all_free(t_game *game)
{
	free(game);
	free(game->wall);
}
