#include "cub3d.h"

int	game_loop(t_game *game)
{
	int x;
	int y;

	key_check(game);
	raycasting(game);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while(++x < WIN_WIDTH)
			game->mlx.addr[y * WIN_WIDTH + x] = game->draw.win_buf[y][x]; //픽셀의 화면 버퍼
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
	return 0;
}

void	images_per_save(t_game *game, char *file_name, int index)
{
	t_mlx img;
	int y, x;

	img.img_test[index] = mlx_xpm_file_to_image(game->mlx.ptr, file_name, &img.w, &img.h);
	img.addr = (int *)mlx_get_data_addr(img.img_test[index], &img.pixel, &img.size, &img.endian);
	y = -1;
	while (++y < img.h)
	{
		x = -1;
		while (++x < img.w)
			game->wall[index][x + img.w * y] = img.addr[x + img.w * y];
	}
	// mlx_destroy_image(game->mlx.ptr, img.img_test[index]);
}

void	wall_info_save(t_game *game)
{
	int		x;
	int 	y;

	images_per_save(game, game->map->no, 0); // N
	images_per_save(game, game->map->so, 1); // S
	images_per_save(game, game->map->we, 2); // W
	images_per_save(game, game->map->ea, 3); // E
}

void	game_init(t_game *game, char *path)
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
	if (!game->map->map[(int)(game->vector.p_posx + game->vector.p_dirx * game->vector.p_speed)][(int)(game->vector.p_posy)])
		game->vector.p_posx += game->vector.p_dirx * game->vector.p_speed;
	if (!game->map->map[(int)(game->vector.p_posx)][(int)(game->vector.p_posy + game->vector.p_diry * game->vector.p_speed)])
		game->vector.p_posy += game->vector.p_diry * game->vector.p_speed;
}

int main(int ac, char *av[])
{
	t_game	*game;

	if (ac != 2)
	{
		write(1, ERROR, ft_strlen(ERROR));
		return BAD_END;
	}
	if (!(game = malloc(sizeof(t_game))))
	{
		write(1, ERROR, ft_strlen(ERROR));
		return BAD_END;
	}
	game->wall = (int **)malloc(sizeof(int *) * 4);
	for (int i = 0; i < 4; i++)
	{
		if (!(game->wall[i] = (int *)malloc(sizeof(int) * tex_size * tex_size)))
		{
			write(1, ERROR, ft_strlen(ERROR));
			return BAD_END;
		}
	}
	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = (int *)mlx_get_data_addr(game->mlx.img, &game->mlx.pixel, &game->mlx.size, &game->mlx.endian);
	game_init(game, av[1]);
	wall_info_save(game);
	mlx_hook(game->mlx.win, 2, 1, &input_key, game);
	mlx_hook(game->mlx.win, 3, 2, &release_key, game);
	mlx_hook(game->mlx.win, 17, 0, &click_exit, game);
	mlx_loop_hook(game->mlx.ptr , &game_loop, game);
	mlx_loop(game->mlx.ptr);
	// all_free(game);
	return GOOD_END;
}
