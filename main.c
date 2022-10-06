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
	print_minimap(game);
	return 0;
}

void	wall_info_save(t_game *game)
{
	t_mlx	img;
	int		x;
	int 	y;

	img.img = mlx_xpm_file_to_image(game->mlx.ptr, "./images/wall_w.xpm", &img.w, &img.h);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.pixel, &img.size, &img.endian);
	y = -1;
	while (++y < img.h)
	{
		x = -1;
		while (++x < img.w)
			game->wall[x + img.w * y] = img.addr[x + img.w * y];
	}
	mlx_destroy_image(game->mlx.ptr, img.img);
}

void	game_init(t_game *game)
{
	game->vector.p_posX = 3.5;
	game->vector.p_posY = 2.5;
	game->vector.p_dirX = -0.5;
	game->vector.p_dirY = 0.0;
	game->vector.planeX = 0.0;
	game->vector.planeY = 0.66;
	game->vector.p_Speed = 0.1;
	game->vector.rotSpeed = 0.06;
}

int main()
{
	t_game	*game;

	if (!(game = malloc(sizeof(t_game))))
	{
		write(1, ERROR, ft_strlen(ERROR));
		return BAD_END;
	}
	if (!(game->wall = (int *)malloc(sizeof(int) * tex_size * tex_size)))
	{
		write(1, ERROR, ft_strlen(ERROR));
		return BAD_END;
	}
	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = (int *)mlx_get_data_addr(game->mlx.img, &game->mlx.pixel, &game->mlx.size, &game->mlx.endian);
	game_init(game);
	wall_info_save(game);
	mlx_hook(game->mlx.win, 2, 1, &input_key, game);
	mlx_hook(game->mlx.win, 3, 2, &release_key, game);
	mlx_hook(game->mlx.win, 17, 0, &click_exit, game);
	mlx_loop_hook(game->mlx.ptr , &game_loop, game);
	mlx_loop(game->mlx.ptr);
	// all_free(game);
	return GOOD_END;
}
