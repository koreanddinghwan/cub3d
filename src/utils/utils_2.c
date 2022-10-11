/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:19:37 by gyumpark          #+#    #+#             */
/*   Updated: 2022/10/11 13:21:12 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_end(void)
{
	write(1, ERROR, ft_strlen(ERROR));
	return (BAD_END);
}

void	game_init(t_game *game, char *av[])
{
	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIN_WIDTH, \
			WIN_HEIGHT, "cub3D");
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = (int *)mlx_get_data_addr(game->mlx.img, &game->mlx.pixel, \
			&game->mlx.size, &game->mlx.endian);
	game_vec_init(game, av[1]);
}

void	mlx_f(t_game *game)
{
	mlx_hook(game->mlx.win, 2, 1, &input_key, game);
	mlx_hook(game->mlx.win, 3, 2, &release_key, game);
	mlx_hook(game->mlx.win, 17, 0, &click_exit, game);
	mlx_loop_hook(game->mlx.ptr, &game_loop, game);
	mlx_loop(game->mlx.ptr);
}
