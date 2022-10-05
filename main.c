# include <fcntl.h> // open
# include <unistd.h> // close, read, write, 
# include <stdio.h> // printf, perror
# include <stdlib.h> // malloc, free, exit
# include <string.h> // strerror
# include <math.h>
# include "./minilibx_opengl_20191021/mlx.h"

/**
 * @brief WASD
 * 
 */
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

/**
 * @brief ESC
 * 
 */
# define ESC 53

/**
 * @brief RESOLUTION, MAP_SIZE
 * 
 */
# define WIN_WIDTH 1280//640 1280
# define WIN_HEIGHT 720//480 720
# define map_Width	7
# define map_Height	7
# define tex_size 64

# define mini_w	64
# define mini_h 48

/**
 * @brief TOOL
 * 
 */
# define ERROR "ERROR\n"
# define GOOD_END 0
# define BAD_END 1

int map[map_Width][map_Height] = {
	{1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1},

};

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	int		*addr;
	int		w;
	int		h;
	int		pixel;
	int		size;
	int		endian;
}				t_mlx;

typedef struct s_vector
{
	double cameraX;			//카메라 평면 상에 x좌표 (-1 ~ 1)
	double p_posX;			//플레이어의 X위치벡터
	double p_posY;			//플레이어의 Y위치벡터
	double p_dirX;			//플레이어의 X방향벡터
	double p_dirY;			//플레이어의 Y방향벡터
	double planeX;			//카메라 평면의 X벡터
	double planeY;			//카메라 평면의 Y벡터
	double rayDirectionX;	//광선의 X방향벡터 (방향벡터 + 카메라평면 * 배수)
	double rayDirectionY;	//광선의 Y방향벡터
	double p_Speed;			//플레이어의 속도
	double rotSpeed;		//회전 속도
}				t_vector;

typedef struct s_dda
{
	double sideDistX;		//현재 위치에서 다음 X면까지의 거리
	double sideDistY;		//현재 위치에서 다음 Y면까지의 거리
	double deltaDistX;		//첫 번째 X면에서 그 다음 X면까지의 광선 이동거리
	double deltaDistY;		//첫 번째 Y면에서 그 다음 Y면까지의 광선 이동거리
	double perpWallDist;	//광선의 이동거리계산 변수
	int mapX;				//좌표상 플레이어의 X위치
	int mapY;				//좌표상 플레이어의 Y위치
	int stepX;				//광선의 방향에 따라 결정 (-1 ~ 1)
	int stepY;				//광선의 방향에 따라 결정 (-1 ~ 1)
}				t_dda;

typedef struct s_draw
{
	int		draw_height;	//벽의 높이
	int		start;			//그릴 시작점
	int		end;			//그릴 마지막점
	int 	hit;			//벽과 부딪혔는지 판별 (0->X, 1->O)
	int 	side;			//0->X면, 1->Y면
	int		texX;			//텍스쳐의 X좌표
	int		texY;			//텍스쳐의 Y좌표
	double	texPos;			//시작 텍스쳐 좌표
	double	step;			//픽셀당 텍스쳐 좌표 증가크기
	double	wallX;			//광선이 부딪힌 벽의 좌표
	int		win_buf[WIN_HEIGHT][WIN_WIDTH]; //픽셀의 화면 버퍼
}				t_draw;

typedef struct s_key
{
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_left;
	int		key_right;
}				t_key;

typedef struct s_minimap
{
	int		*mini_addr;
	void	*mini_img;
	int		pixel;
	int		size;
	int		endian;
	int		ratio_w;
	int		ratio_h;
}				t_minimap;

typedef struct s_bonus
{

}				t_bonus;

typedef struct s_game
{
	t_mlx	mlx;
	t_vector vector;
	t_draw	draw;
	t_key	key;
	t_minimap mini;
	int		*wall;
}				t_game;

void	rotate(t_game *game, double speed);

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	game_init(t_game *game)
{
	game->vector.p_posX = 3.5;
	game->vector.p_posY = 3.5;
	game->vector.p_dirX = -0.5;
	game->vector.p_dirY = 0.0;
	game->vector.planeX = 0.0;
	game->vector.planeY = 0.66;
	game->vector.p_Speed = 0.1;
	game->vector.rotSpeed = 0.1;
}

void	dda_algorithm(t_game *game, t_dda *dda)
{
	while (game->draw.hit == 0)
	{
		if (dda->sideDistX < dda->sideDistY)
		{
			dda->sideDistX += dda->deltaDistX;
			dda->mapX += dda->stepX;
			game->draw.side = 0;
		}
		else
		{
			dda->sideDistY += dda->deltaDistY;
			dda->mapY += dda->stepY;
			game->draw.side = 1;
		}
		if (map[dda->mapX][dda->mapY] > 0)
			game->draw.hit = 1;
	}
}

void	dda_init(t_game *game, t_dda *dda)
{
	dda->mapX = (int)(game->vector.p_posX);
	dda->mapY = (int)(game->vector.p_posY);
	dda->deltaDistX = fabs(1 / game->vector.rayDirectionX);
	dda->deltaDistY = fabs(1 / game->vector.rayDirectionY);
	game->draw.hit = 0;

	if (game->vector.rayDirectionX < 0)
	{
		dda->stepX = -1;
		dda->sideDistX = (game->vector.p_posX - dda->mapX) * dda->deltaDistX;
	}
	else
	{
		dda->stepX = 1;
		dda->sideDistX = (dda->mapX + 1.0 - game->vector.p_posX) * dda->deltaDistX;
	}
	if (game->vector.rayDirectionY < 0)
	{
		dda->stepY = -1;
		dda->sideDistY = (game->vector.p_posY - dda->mapY) * dda->deltaDistY;
	}
	else
	{
		dda->stepY = 1;
		dda->sideDistY = (dda->mapY + 1.0 - game->vector.p_posY) * dda->deltaDistY;
	}
	dda_algorithm(game, dda);
}

void	cal_camera_dir(t_game *game, t_dda *dda, int x)
{
	if (game->draw.side == 0)	// 부딪힌 광선이 x면이면 x방향으로 몇칸지나갔는지 계산
		dda->perpWallDist = (dda->mapX - game->vector.p_posX + (1 - dda->stepX) / 2) / game->vector.rayDirectionX;
	else	// 부딪힌 광선이 y면
		dda->perpWallDist = (dda->mapY - game->vector.p_posY + (1 - dda->stepY) / 2) / game->vector.rayDirectionY;
	game->draw.draw_height = (int)(WIN_HEIGHT / dda->perpWallDist);
	game->draw.start = (-game->draw.draw_height / 2) + (WIN_HEIGHT / 2);
	if (game->draw.start < 0)
		game->draw.start = 0;
	game->draw.end = (game->draw.draw_height / 2) + (WIN_HEIGHT / 2);
	if (game->draw.end >= WIN_HEIGHT)
		game->draw.end = WIN_HEIGHT - 1;
	if (game->draw.side == 0)
		game->draw.wallX = game->vector.p_posY + dda->perpWallDist * game->vector.rayDirectionY;
	else
		game->draw.wallX = game->vector.p_posX + dda->perpWallDist * game->vector.rayDirectionX;
	game->draw.wallX = game->draw.wallX - (int)game->draw.wallX;
	game->draw.texX = (int)(game->draw.wallX * (double)tex_size);
	if (game->draw.side == 0 && game->vector.rayDirectionX > 0)
		game->draw.texX = tex_size - game->draw.texX - 1;
	if (game->draw.side == 1 && game->vector.rayDirectionY < 0)
		game->draw.texX = tex_size - game->draw.texX - 1;
	game->draw.step = 1.0 * tex_size / game->draw.draw_height;
	game->draw.texPos = (game->draw.start - WIN_HEIGHT / 2 + game->draw.draw_height / 2) * game->draw.step;
        for (int y = 0; y < WIN_HEIGHT; y++)
        {
            game->draw.win_buf[y][x] = 0x000000; 
            game->draw.win_buf[WIN_HEIGHT - y - 1][x] = 0xFFFFFF;
        }
	for (int y = game->draw.start; y < game->draw.end; y++)
	{
		game->draw.texY = (int)game->draw.texPos & (tex_size - 1);
		game->draw.texPos += game->draw.step;
		int color = game->wall[tex_size * game->draw.texY + game->draw.texX];
		if (game->draw.side == 1)
			color = (color >> 8);  // & 8355711
		game->draw.win_buf[y][x] = color; //픽셀의 화면 버퍼
	}
}

void	paint(t_game *game, int y, int x, char *color)
{
	int	i;
	int	j;

	i = y - 1;
	while (++i < y + game->mini.ratio_h)
	{
		j = x - 1;
		while (++j < x + game->mini.ratio_w)
		{
			game->mini.mini_addr[i * mini_w + j] = atoi(color);
		}
	}
}

void	print_minimap(t_game *game)
{
	game->mini.mini_img = mlx_new_image(game->mlx.ptr, mini_w, mini_h);
	game->mini.mini_addr = (int *)mlx_get_data_addr(game->mini.mini_img, &game->mini.pixel, &game->mini.size, &game->mini.endian);
	int x;
	int y;

	y = 0;
	while (x < mini_w)
	{
		x = 0;
		while (x < mini_h)
		{
			if (x == (int)game->vector.p_posX && y == (int)game->vector.p_posY)
				paint(game, x * game->mini.ratio_h, y * game->mini.ratio_w, "#FF0000");
			else if (map[(int)(y)][(int)(x)] == '\0')
				break;
			else if (map[(int)(y)][(int)(x)] == '0')
				paint(game, x * game->mini.ratio_h, y * game->mini.ratio_w, "#FFFFFF");
			else if (map[(int)(y)][(int)(x)] == '1')
				paint(game, x * game->mini.ratio_h, y * game->mini.ratio_w, "#FFFAFA");
			else
				paint(game, x * game->mini.ratio_h, y * game->mini.ratio_w, "#FFFAFA");
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mini.mini_img, 0, 0);
}

int	game_loop(t_game *game)
{
	if (game->key.key_w)
	{
		if (!map[(int)(game->vector.p_posX + game->vector.p_dirX * game->vector.p_Speed)][(int)(game->vector.p_posY)])
			game->vector.p_posX += game->vector.p_dirX * game->vector.p_Speed;
		if (!map[(int)(game->vector.p_posX)][(int)(game->vector.p_posY + game->vector.p_dirY * game->vector.p_Speed)])
			game->vector.p_posY += game->vector.p_dirY * game->vector.p_Speed;
	}
	if (game->key.key_s)
	{
		if (!map[(int)(game->vector.p_posX - game->vector.p_dirX * game->vector.p_Speed)][(int)(game->vector.p_posY)])
			game->vector.p_posX -= game->vector.p_dirX * game->vector.p_Speed;
		if (!map[(int)(game->vector.p_posX)][(int)(game->vector.p_posY - game->vector.p_dirY * game->vector.p_Speed)])
			game->vector.p_posY -= game->vector.p_dirY * game->vector.p_Speed;
	}
	if (game->key.key_a)
	{
		if (!map[(int)(game->vector.p_posX + game->vector.p_dirX * cos(M_PI_2) - game->vector.p_dirY * sin(M_PI_2))][(int)(game->vector.p_posY)])
			game->vector.p_posX += game->vector.p_dirX * cos(M_PI_2) - game->vector.p_dirY * sin(M_PI_2);
		if (!map[(int)(game->vector.p_posX)][(int)(game->vector.p_posY + game->vector.p_dirX * sin(M_PI_2) + game->vector.p_dirY * cos(M_PI_2))])
			game->vector.p_posY += game->vector.p_dirX * sin(M_PI_2) + game->vector.p_dirY * cos(M_PI_2);
	}
	if (game->key.key_d)
	{
		if (!map[(int)(game->vector.p_posX + game->vector.p_dirX * cos(-M_PI_2) - game->vector.p_dirY * sin(-M_PI_2))][(int)(game->vector.p_posY)])
			game->vector.p_posX += game->vector.p_dirX * cos(-M_PI_2) - game->vector.p_dirY * sin(-M_PI_2);
		if (!map[(int)(game->vector.p_posX)][(int)(game->vector.p_posY + game->vector.p_dirX * sin(-M_PI_2) + game->vector.p_dirY * cos(-M_PI_2))])
			game->vector.p_posY += game->vector.p_dirX * sin(-M_PI_2) + game->vector.p_dirY * cos(-M_PI_2);
	}
	if (game->key.key_left)
	{
		rotate(game, game->vector.rotSpeed);
	}
	if (game->key.key_right)
	{
		rotate(game, -game->vector.rotSpeed);
	}
	t_dda dda;
	int x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->vector.cameraX = (2 * x / (double)(WIN_WIDTH)) - 1;
		game->vector.rayDirectionX = game->vector.p_dirX + game->vector.planeX * game->vector.cameraX;
		game->vector.rayDirectionY = game->vector.p_dirY + game->vector.planeY * game->vector.cameraX;
		dda_init(game, &dda);
		cal_camera_dir(game, &dda, x);
		x++;
	}
	for (int y = 0; y < WIN_HEIGHT; y++)
		for (int x = 0; x < WIN_WIDTH; x++)
			game->mlx.addr[y * WIN_WIDTH + x] = game->draw.win_buf[y][x]; //픽셀의 화면 버퍼
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
	// print_minimap(game);
	return 0;
}

void	rotate(t_game *game, double speed)
{
	double	o_dirX = game->vector.p_dirX;
	double	o_planeX = game->vector.planeX;

	game->vector.p_dirX = game->vector.p_dirX * cos(speed) - game->vector.p_dirY * sin(speed);
	game->vector.p_dirY = o_dirX * sin(speed) + game->vector.p_dirY * cos(speed);
	game->vector.planeX = game->vector.planeX * cos(speed) - game->vector.planeY * sin(speed);
	game->vector.planeY = o_planeX * sin(speed) + game->vector.planeY * cos(speed);
}

int input_key(int key, t_game *game)
{
	if (key == W)
	{
		game->key.key_w = 1;
	}
	if (key == S)
	{
		game->key.key_s = 1;
	}
	if (key == A)
	{
		game->key.key_a = 1;
	}
	if (key == D)
	{
		game->key.key_d = 1;
	}
	if (key == LEFT)
	{
		game->key.key_left = 1;
	}
	if (key == RIGHT)
	{
		game->key.key_right = 1;
	}
	if (key == ESC)
		exit(0);
	return (0);
}

int	click_exit()
{
	exit(1);
	return (1);
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

void	show_wall(t_game *game)
{
	t_mlx	img;

	img.img = mlx_xpm_file_to_image(game->mlx.ptr, "./images/wall_w.xpm", &img.w, &img.h);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.pixel, &img.size, &img.endian);
	int y = 0;
	while (y < img.h)
	{
		int x = 0;
		while (x < img.w)
		{
			game->wall[x + img.w * y] = img.addr[x + img.w * y];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx.ptr, img.img);
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
	game_init(game);

	game->mlx.ptr = mlx_init();

	show_wall(game);

	game->mlx.win = mlx_new_window(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = (int *)mlx_get_data_addr(game->mlx.img, &game->mlx.pixel, &game->mlx.size, &game->mlx.endian);
	mlx_hook(game->mlx.win, 2, 1, &input_key, game);
	mlx_hook(game->mlx.win, 3, 2, &release_key, game);
	mlx_hook(game->mlx.win, 17, 0, &click_exit, game);
	mlx_loop_hook(game->mlx.ptr , &game_loop, game);
	mlx_loop(game->mlx.ptr);

	free(game);
	return GOOD_END;
}
