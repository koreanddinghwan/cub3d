# include <fcntl.h> // open
# include <unistd.h> // close, read, write, 
# include <stdio.h> // printf, perror
# include <stdlib.h> // malloc, free, exit
# include <string.h> // strerror
# include <math.h>
# include "./minilibx_opengl_20191021/mlx.h"

/* WASD */
# define W 13
# define A 0
# define S 1
# define D 2

/* ESC */
# define ESC 53

# define ERROR "ERROR\n"
# define GOOD_END 0
# define BAD_END 1
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

int map[5][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 'N', 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
	};

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	int		*addr;

	int		*wall;
	int		pixel;
	int		size;
	int		endian;
}				t_mlx;

typedef struct s_vector
{
	double p_posX;
	double p_posY;
	double p_dirX;
	double p_dirY;
	double planeX;
	double planeY;
	double playerSpeed;
	double rotSpeed;
}				t_vector;

typedef struct s_game
{
	t_mlx	mlx;
	t_vector vector;
}				t_game;

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*mlx_new_image(void *mlx_ptr, int width, int height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_map(int map[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void	game_init(t_game *game)
{
	game->vector.p_posX = 0;
	game->vector.p_posY = 0;
	game->vector.p_dirX = 0;
	game->vector.p_dirY = 0;
	game->vector.planeX = 0;
	game->vector.planeY = 0;
	game->vector.playerSpeed = 0.1;
	game->vector.rotSpeed = 0.1;
}

int	game_loop(t_game *game)
{
	// int x;

	// x = 0;
	// while (x < WIN_WIDTH)
	// {
	// 	double cameraX = (2 * x / (double)(WIN_WIDTH)) - 1;
		
	// 	double rayDirectionX = game->vector.p_dirX + game->vector.planeX * cameraX;
	// 	double rayDirectionY = game->vector.p_dirY + game->vector.planeY * cameraX;

	// 	int mapX = (int)(game->vector.p_posX);
	// 	int mapY = (int)(game->vector.p_posY);

	// 	double sideDistX;
	// 	double sideDistY;

	// 	double deltaDistX = fabs(1 / rayDirectionX);
	// 	double deltaDistY = fabs(1 / rayDirectionY);

	// 	double perpWallDist;

	// 	int stepX;
	// 	int stepY;

	// 	int hit = 0;
	// 	int side;


	// }
	int y = 0;
	while (y <= WIN_HEIGHT)
	{
		int x = 0;
		while (x <= WIN_WIDTH)
		{
			game->mlx.addr[x + WIN_WIDTH * y] = 0xFF0000;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
	return 0;
}

int input_key(int key, t_game *game)
{

}

void	show_wall(t_game *game)
{
	int		w;
	int		h;

	w = 640;
	h = 480;

	game->mlx.img = mlx_xpm_file_to_image(game->mlx.ptr, "wall_w.xpm", &w, &h);
	game->mlx.addr = (int *)mlx_get_data_addr(game->mlx.img, &game->mlx.pixel, &game->mlx.size, &game->mlx.endian);
	int y = 0;
	while (y <= WIN_HEIGHT)
	{
		int x = 0;
		while (x <= WIN_WIDTH)
		{
			game->mlx.wall[x + WIN_WIDTH * y] = game->mlx.addr[x + WIN_WIDTH * y];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx.ptr, game->mlx.img);
}

int main()
{
	t_game	*game;

	// void	*img;
	// int		x;
	// int		y;

	// x = 64;
	// y = 64;

	if (!(game = malloc(sizeof(t_game))))
	{
		write(1, ERROR, ft_strlen(ERROR));
		return BAD_END;
	}
	if (!(game->mlx.wall = (int *)malloc(sizeof(int) * WIN_HEIGHT * WIN_WIDTH)))
	{
		write(1, ERROR, ft_strlen(ERROR));
		return BAD_END;
	}

	
	game->mlx.ptr = mlx_init();
	game_init(game);
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = (int *)mlx_get_data_addr(game->mlx.img, &game->mlx.pixel, &game->mlx.size, &game->mlx.endian);
	mlx_loop_hook(game->mlx.ptr , &game_loop, &game);
    // mlx_hook(game->mlx.win, 2, 0, &input_key, &game);
	show_wall(game);
	mlx_loop(game->mlx.ptr);
	free(game);
	print_map(map);
	return GOOD_END;
	// img = mlx_xpm_file_to_image(game->mlx.ptr, "./wall_w.xpm", &x, &y);
	// mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, img, 0, 0);
}
