#include "cub3d.h"

// void	paint(t_game *game, int x, int y, int color)
// {}

void	print_minimap(t_game *game)
{
	game->mini.mini_img = mlx_new_image(game->mlx.ptr, mini_w, mini_h);
	game->mini.mini_addr = (int *)mlx_get_data_addr(game->mini.mini_img, &game->mini.pixel, &game->mini.size, &game->mini.endian);
	game->mini.ratio_w = WIN_WIDTH * 0.25 / map_Width;
	game->mini.ratio_h = WIN_HEIGHT * 0.25 / map_Height;
	int x;
	int y;

	x = -1;
	while (++x < mini_w)
	{
		for (int y = 0; y < mini_h; y++)
        {
            game->mini.mini_buf[x][y] = 0xFFFFFF;
			if (x == (int)game->vector.p_posX && y == (int)game->vector.p_posY)
			{
				game->mini.mini_buf[x][y] = 16711680;
				// paint(game, 16711680); //16711680
			}
        }
	}
	for (int y = 0; y < mini_h; y++)
		for (int x = 0; x < mini_w; x++)
			game->mini.mini_addr[y * mini_w + x] = game->mini.mini_buf[y][x];
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mini.mini_img, 0, 0);
}