#ifndef GLOBAL_H
# define GLOBAL_H

# include <fcntl.h> // open
# include <unistd.h> // close, read, write, 
# include <stdio.h> // printf, perror
# include <stdlib.h> // malloc, free, exit
# include <string.h> // strerror
# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "libft.h"

/**
 * @brief WASD, ->, <-
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
 * @brief MAP_SIZE
 * 
 */
# define WIN_WIDTH 1280//640 1280 1920
# define WIN_HEIGHT 720//480 720 1080
# define map_Width	7
# define map_Height	7

# define tex_size 64

# define mini_w	200
# define mini_h 100

/**
 * @brief TOOL
 * 
 */
# define ERROR "ERROR\n"
# define GOOD_END 0
# define BAD_END 1

static int map[map_Height][map_Width] = {
	{1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1},

};

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	void	*img_test[4];
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
	int		mini_buf[mini_w][mini_h];
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
	int		**wall;
}				t_game;

/*
*	key.c
*/
int input_key(int key, t_game *game);
int	release_key(int key, t_game *game);
int	click_exit(void);
void	key_check(t_game *game);

/*
*	ray.c
*/
void    raycasting(t_game *game);
void	dda_init(t_game *game, t_dda *dda);
void	dda_algorithm(t_game *game, t_dda *dda);
void	cal_camera_dir(t_game *game, t_dda *dda, int x);

/*
*	util.c
*/
void	rotate(t_game *game, double speed);

void	print_minimap(t_game *game);

#endif
