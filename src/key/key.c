#include "cub3d.h"

// press key
int input_key(int key, t_game *game)
{
	if (key == W)
		game->key.key_w = 1;
	if (key == S)
		game->key.key_s = 1;
	if (key == A)
		game->key.key_a = 1;
	if (key == D)
		game->key.key_d = 1;
	if (key == LEFT)
		game->key.key_left = 1;
	if (key == RIGHT)
		game->key.key_right = 1;
	if (key == ESC)
		exit(0);
	return (0);
}

// detach key
int	release_key(int key, t_game *game)
{
	if (key == W)
		game->key.key_w = 0;
	if (key == S)
		game->key.key_s = 0;
	if (key == A)
		game->key.key_a = 0;
	if (key == D)
		game->key.key_d = 0;
	if (key == LEFT)
		game->key.key_left = 0;
	if (key == RIGHT)
		game->key.key_right = 0;
	if (key == ESC)
		exit(0);
	return (0);
}

// click event
int	click_exit()
{
	exit(0);
	return (0);
}

// key flag check
void    key_check(t_game *game)
{
    if (game->key.key_w)
	{
		if (!game->map->map[(int)(game->vector.p_posX + game->vector.p_dirX * game->vector.p_Speed)][(int)(game->vector.p_posY)])
			game->vector.p_posX += game->vector.p_dirX * game->vector.p_Speed;
		if (!game->map->map[(int)(game->vector.p_posX)][(int)(game->vector.p_posY + game->vector.p_dirY * game->vector.p_Speed)])
			game->vector.p_posY += game->vector.p_dirY * game->vector.p_Speed;
	}
	if (game->key.key_s)
	{
		if (!game->map->map[(int)(game->vector.p_posX - game->vector.p_dirX * game->vector.p_Speed)][(int)(game->vector.p_posY)])
			game->vector.p_posX -= game->vector.p_dirX * game->vector.p_Speed;
		if (!game->map->map[(int)(game->vector.p_posX)][(int)(game->vector.p_posY - game->vector.p_dirY * game->vector.p_Speed)])
			game->vector.p_posY -= game->vector.p_dirY * game->vector.p_Speed;
	}
	if (game->key.key_a)
	{
		if (!game->map->map[(int)(game->vector.p_posX + game->vector.p_dirX * cos(M_PI_2) - game->vector.p_dirY * sin(M_PI_2))][(int)(game->vector.p_posY)])
			game->vector.p_posX += game->vector.p_dirX * cos(M_PI_2) * game->vector.p_Speed - game->vector.p_dirY * sin(M_PI_2) * game->vector.p_Speed;
		if (!game->map->map[(int)(game->vector.p_posX)][(int)(game->vector.p_posY + game->vector.p_dirX * sin(M_PI_2) + game->vector.p_dirY * cos(M_PI_2))])
			game->vector.p_posY += game->vector.p_dirX * sin(M_PI_2) * game->vector.p_Speed + game->vector.p_dirY * cos(M_PI_2) * game->vector.p_Speed;
	}
	if (game->key.key_d)
	{
		if (!game->map->map[(int)(game->vector.p_posX + game->vector.p_dirX * cos(-M_PI_2) - game->vector.p_dirY * sin(-M_PI_2))][(int)(game->vector.p_posY)])
			game->vector.p_posX += game->vector.p_dirX * cos(-M_PI_2) * game->vector.p_Speed - game->vector.p_dirY * sin(-M_PI_2) * game->vector.p_Speed;
		if (!game->map->map[(int)(game->vector.p_posX)][(int)(game->vector.p_posY + game->vector.p_dirX * sin(-M_PI_2) + game->vector.p_dirY * cos(-M_PI_2))])
			game->vector.p_posY += game->vector.p_dirX * sin(-M_PI_2) * game->vector.p_Speed + game->vector.p_dirY * cos(-M_PI_2) * game->vector.p_Speed;
	}
	if (game->key.key_left)
		rotate(game, game->vector.rotSpeed);
	if (game->key.key_right)
		rotate(game, -game->vector.rotSpeed);
}