#include "cub3d.h"

void    raycasting(t_game *game)
{
	t_dda dda;
	int x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		game->vector.multiple = (2 * x / (double)(WIN_WIDTH)) - 1;
		game->vector.rayDirectionX = game->vector.p_dirX + game->vector.planeX * game->vector.multiple;
		game->vector.rayDirectionY = game->vector.p_dirY + game->vector.planeY * game->vector.multiple;
		dda.mapX = (int)(game->vector.p_posX);
		dda.mapY = (int)(game->vector.p_posY);
		dda.deltaDistX = fabs(1 / game->vector.rayDirectionX);
		dda.deltaDistY = fabs(1 / game->vector.rayDirectionY);
		game->draw.hit = 0;
		dda_init(game, &dda);
		cal_camera_dir(game, &dda, x);
	}
}

void	dda_init(t_game *game, t_dda *dda)
{
	if (game->vector.rayDirectionX < 0)
	{
		dda->stepX = -1;
		dda->sideDistX = (game->vector.p_posX - dda->mapX) * dda->deltaDistX;
	}
	else
	{
		dda->stepX = 1;
		dda->sideDistX = (dda->mapX + 1.0 - game->vector.p_posX) * dda->deltaDistX;
	}
	if (game->vector.rayDirectionY < 0)
	{
		dda->stepY = -1;
		dda->sideDistY = (game->vector.p_posY - dda->mapY) * dda->deltaDistY;
	}
	else
	{
		dda->stepY = 1;
		dda->sideDistY = (dda->mapY + 1.0 - game->vector.p_posY) * dda->deltaDistY;
	}
	dda_algorithm(game, dda);
}

void	dda_algorithm(t_game *game, t_dda *dda)
{
	while (game->draw.hit == 0)
	{
		if (dda->sideDistX < dda->sideDistY)
		{
			dda->sideDistX += dda->deltaDistX;
			dda->mapX += dda->stepX;
			game->draw.side = 0;
		}
		else
		{
			dda->sideDistY += dda->deltaDistY;
			dda->mapY += dda->stepY;
			game->draw.side = 1;
		}
		if (game->map->map[dda->mapX][dda->mapY] == 1)
			game->draw.hit = 1;
	}
}

void	cal_camera_dir(t_game *game, t_dda *dda, int x)
{
	if (game->draw.side == 0)
		dda->perpWallDist = (dda->mapX - game->vector.p_posX + (1 - dda->stepX) / 2) / game->vector.rayDirectionX;
	else
		dda->perpWallDist = (dda->mapY - game->vector.p_posY + (1 - dda->stepY) / 2) / game->vector.rayDirectionY;
	game->draw.draw_height = (int)(WIN_HEIGHT/ dda->perpWallDist);
	game->draw.start = (-game->draw.draw_height / 2) + (WIN_HEIGHT / 2);
	if (game->draw.start < 0)
		game->draw.start = 0;
	game->draw.end = (game->draw.draw_height / 2) + (WIN_HEIGHT / 2);
	if (game->draw.end >= WIN_HEIGHT)
		game->draw.end = WIN_HEIGHT - 1;

	if (game->draw.side == 0)
		game->draw.wallX = game->vector.p_posY + dda->perpWallDist * game->vector.rayDirectionY;
	else
		game->draw.wallX = game->vector.p_posX + dda->perpWallDist * game->vector.rayDirectionX;
	game->draw.wallX = game->draw.wallX - (int)game->draw.wallX;
	game->draw.texX = (int)(game->draw.wallX * (double)tex_size);

	if (game->draw.side == 0 && game->vector.rayDirectionX > 0)
		game->draw.texX = tex_size - game->draw.texX - 1;
	if (game->draw.side == 1 && game->vector.rayDirectionY < 0)
		game->draw.texX = tex_size - game->draw.texX - 1;
	game->draw.step = 1.0 * tex_size / game->draw.draw_height;
	game->draw.texPos = (game->draw.start - WIN_HEIGHT / 2 + game->draw.draw_height / 2) * game->draw.step;
	draw(game, x);
}

void	draw(t_game *game, int x)
{
	int y = -1;

	while (++y < WIN_HEIGHT)
	{
		game->draw.win_buf[y][x] = game->map->f_rgb;
		game->draw.win_buf[WIN_HEIGHT - y - 1][x] = game->map->c_rgb;
	}
	y = game->draw.start - 1;
	while (++y < game->draw.end)
	{
		if (game->draw.side == 0)
		{
			if ((game->vector.rayDirectionY <= 0 && game->vector.rayDirectionX <= 0) || (game->vector.rayDirectionY > 0) && game->vector.rayDirectionX <= 0)
				draw_dir_wall(game, y, x, 0);
			else
				draw_dir_wall(game, y, x, 1);
		}
		else if (game->draw.side == 1 && ((game->vector.rayDirectionY <= 0 && game->vector.rayDirectionX <= 0) || (game->vector.rayDirectionY <= 0) && game->vector.rayDirectionX > 0))
			draw_dir_wall(game, y, x, 2);
		else
			draw_dir_wall(game, y, x, 3);
	}
}