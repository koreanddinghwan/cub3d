/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:18:49 by gyumpark          #+#    #+#             */
/*   Updated: 2022/10/11 13:24:08 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_game *game)
{
	int	x;
	int	y;

	key_check(game);
	raycasting(game);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			game->mlx.addr[y * WIN_WIDTH + x] = game->draw.win_buf[y][x];
	}
	return (mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->mlx.img, 0, 0));
}

void	images_per_save(t_game *game, char *file_name, int index)
{
	t_mlx	img;
	int		y;
	int		x;

	img.img_test[index] = mlx_xpm_file_to_image(game->mlx.ptr, file_name, \
		&img.w, &img.h);
	img.addr = (int *)mlx_get_data_addr(img.img_test[index], &img.pixel, \
		&img.size, &img.endian);
	y = -1;
	while (++y < img.h)
	{
		x = -1;
		while (++x < img.w)
			game->wall[index][x + img.w * y] = img.addr[x + img.w * y];
	}
	mlx_destroy_image(game->mlx.ptr, img.img_test[index]);
}

void	wall_info_save(t_game *game)
{
	images_per_save(game, game->map->no, 0);
	images_per_save(game, game->map->so, 1);
	images_per_save(game, game->map->we, 2);
	images_per_save(game, game->map->ea, 3);
}

void	game_vec_init(t_game *game, char *path)
{
	game->map = parser(path);
	game->vector.p_posx = game->map->p_x;
	game->vector.p_posy = game->map->p_y;
	game->vector.p_dirx = -1;
	game->vector.p_diry = 0.0;
	game->vector.planex = 0.0;
	game->vector.planey = 0.66;
	if (game->map->view == PLAYER_N)
		game->vector.p_dirx = -1;
	else if (game->map->view == PLAYER_S)
	{
		game->vector.p_dirx = 1;
		game->vector.planey = -0.66;
	}
	else if (game->map->view == PLAYER_W)
		rotate(game, M_PI_2);
	else
		rotate(game, -M_PI_2);
	game->vector.p_speed = 0.1;
	game->vector.rotspeed = 0.06;
	move_w(game);
}

int	main(int ac, char *av[])
{
	t_game	*game;
	int		i;

	if (ac != 2)
		return (err_end());
	game = malloc(sizeof(t_game));
	if (!game)
		return (err_end());
	game->wall = (int **)malloc(sizeof(int *) * 4);
	i = -1;
	while (++i < 4)
	{
		game->wall[i] = (int *)malloc(sizeof(int) * TEX_SIZE * TEX_SIZE);
		if (!(game->wall[i]))
			return (err_end());
	}
	game_init(game, av);
	wall_info_save(game);
	mlx_f(game);
	all_free(game);
	return (GOOD_END);
}
