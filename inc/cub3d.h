/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:20:25 by gyumpark          #+#    #+#             */
/*   Updated: 2022/10/11 13:21:46 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TEX_SIZE 64
# define ERROR "Error\n"
# define GOOD_END 0
# define BAD_END 1

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "libft.h"
# include "./parser.h"

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
	double	multiple;
	double	p_posx;
	double	p_posy;
	double	p_dirx;
	double	p_diry;			
	double	planex;			
	double	planey;			
	double	raydirectionx;
	double	raydirectiony;
	double	p_speed;
	double	rotspeed;
}				t_vector;

typedef struct s_dda
{
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		mapx;				
	int		mapy;				
	int		stepx;
	int		stepy;
}				t_dda;

typedef struct s_draw
{
	int		draw_height;
	int		start;
	int		end;
	int		hit;
	int		side;
	int		texx;
	int		texy;
	double	texpos;
	double	step;
	double	wallx;
	int		win_buf[WIN_HEIGHT][WIN_WIDTH];
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

typedef struct s_game
{
	t_mlx		mlx;
	t_vector	vector;
	t_draw		draw;
	t_key		key;
	t_map		*map;
	int			**wall;
}				t_game;

/*
 *	key.c
 */
int		input_key(int key, t_game *game);
int		release_key(int key, t_game *game);
int		click_exit(void);
void	key_check(t_game *game);

/*
 *	move.c
 */
void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);

/*
 *	ray.c
 */
void	raycasting(t_game *game);
void	dda_init(t_game *game, t_dda *dda);
void	dda_algorithm(t_game *game, t_dda *dda);
void	cal_camera_dir(t_game *game, t_dda *dda, int x);
void	draw(t_game *game, int x);

/*
 *	util.c
 */
void	rotate(t_game *game, double speed);
void	draw_dir_wall(t_game *game, int y, int x, int index);
void	f_c_draw(t_game *game, int x);
void	cal_tex(t_game *game);
void	all_free(t_game *game);
/*
 *	util_2.c
 */
int		err_end(void);
void	game_init(t_game *game, char *av[]);
void	mlx_f(t_game *game);
void	game_vec_init(t_game *game, char *path);

/*
 *	main.c
 */
int		game_loop(t_game *game);

#endif
