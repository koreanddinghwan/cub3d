#include "cub3d.h"

void	rotate(t_game *game, double speed)
{
	double	o_dirX = game->vector.p_dirX;
	double	o_planeX = game->vector.planeX;

	game->vector.p_dirX = game->vector.p_dirX * cos(speed) - game->vector.p_dirY * sin(speed);
	game->vector.p_dirY = o_dirX * sin(speed) + game->vector.p_dirY * cos(speed);
	game->vector.planeX = game->vector.planeX * cos(speed) - game->vector.planeY * sin(speed);
	game->vector.planeY = o_planeX * sin(speed) + game->vector.planeY * cos(speed);
}

void	draw_dir_wall(t_game *game, int y, int x, int index)
{
	game->draw.texY = (int)game->draw.texPos & (tex_size - 1);
	game->draw.texPos += game->draw.step;
	game->draw.win_buf[y][x] = game->wall[index][tex_size * game->draw.texY + game->draw.texX]; //픽셀의 화면 버퍼
}

void    all_free(t_game *game)
{
    // free(game);
    // free(game->wall);
}