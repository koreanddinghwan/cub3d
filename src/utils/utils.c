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

void    all_free(t_game *game)
{
    // free(game);
    // free(game->wall);
}