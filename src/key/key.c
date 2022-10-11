/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:19:05 by gyumpark          #+#    #+#             */
/*   Updated: 2022/10/11 13:19:13 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	input_key(int key, t_game *game)
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

int	click_exit(void)
{
	exit(0);
	return (0);
}

void	key_check(t_game *game)
{
	if (game->key.key_w)
		move_w(game);
	if (game->key.key_s)
		move_s(game);
	if (game->key.key_a)
		move_a(game);
	if (game->key.key_d)
		move_d(game);
	if (game->key.key_left)
		rotate(game, game->vector.rotspeed);
	if (game->key.key_right)
		rotate(game, -game->vector.rotspeed);
}
