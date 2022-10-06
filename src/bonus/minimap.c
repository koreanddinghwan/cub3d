#include "cub3d.h"

void	paint(t_game *game, int y, int x, int color)
{
	game->mini.mini_buf[x][y] = color;
}

void	print_minimap(t_game *game)
{
	game->mini.mini_img = mlx_new_image(game->mlx.ptr, mini_w, mini_h);
	game->mini.mini_addr = (int *)mlx_get_data_addr(game->mini.mini_img, &game->mini.pixel, &game->mini.size, &game->mini.endian);
	game->mini.ratio_w = mini_w / WIN_WIDTH;
	game->mini.ratio_h = mini_h / WIN_HEIGHT;
	int x;
	int y;

	x = 0;
	while (x < mini_w)
	{
		x++;
		for (int y = 0; y < mini_h; y++)
        {
            game->mini.mini_buf[y][x] = 0xFFFFFF; 
			if (x == (int)game->vector.p_posX && y == (int)game->vector.p_posY)
				paint(game, y * game->mini.ratio_w, x * game->mini.ratio_h, 16711680); //16711680
        }
	}
	for (int y = 0; y < mini_h; y++)
		for (int x = 0; x < mini_w; x++)
			game->mini.mini_addr[y * mini_w + x] = game->mini.mini_buf[y][x];
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mini.mini_img, 0, 0);
}