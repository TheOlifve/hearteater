/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:03:31 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/16 22:51:49 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __APPLE__
#  define AUDIO "/usr/bin/afplay"
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include "./libs/libft/libft.h"
# include "./libs/mlx/mlx.h"

typedef struct s_gmae {
	void	*mlx;
	void	*mlx_win;
	int		player_pid;
	int		win_width;
	int		win_height;
	int		coins;
	int		p_x;
	int		p_y;
	int32_t	pid;
	int		door_x;
	int		door_y;
	int		score;
	int		d_img;

	char	**map;
	char	**map2;
	char	*map3;
	void	*hb;
	void	*h1;
	void	*empty;
	void	*door;
	void	*door2;
	void	*door3;
	void	*door4;
	void	*door5;
	void	*door6;
	void	*door7;
	void	*flw;
	void	*door1;
	void	*g_l2;
	void	*g_r2;
	void	*g_b2;
	void	*g_front2;
	void	*wall_01;
	void	*wall_d;
	void	*wall_dl;
	void	*wall_dr;
	void	*wall_l;
	void	*wall_r;
	void	*wall_u;
	void	*wall_ul;
	void	*wall_ur;
	void	*exit;
}				t_game;

int		ft_exit(t_game *game);
int		check_all(int argc, char **argv, t_game *game);
int		ft_error_print(char *str);
int		map_r(char *file, t_game *game);
void	door(t_game *game);
int		map_line_len(char **map, int len);
void	win_size(t_game *game);
void	img_add(t_game *game);
void	empty(t_game *game, int i, int j);
int		map_cut(char *map);
void	wall(t_game *game, int i, int j);
void	girl_render(t_game *game);
int		key_press(int key, t_game *game);
void	move_right(t_game *game, int i, int j);
void	move_left(t_game *game, int i, int j);
void	move_up(t_game *game, int i, int j);
void	move_down(t_game *game, int i, int j);
void	draw_text(t_game *game);
void	wall_add(t_game *game);
int		anim(t_game *game);
int		logic(t_game *game);

#endif