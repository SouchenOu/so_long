/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:45:39 by souchen           #+#    #+#             */
/*   Updated: 2022/04/04 09:42:14 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define RED_PIXEL	0xFF0000
# define LEFT_KEY	123	
# define RIGHT_KEY	124	
# define UP_KEY		126
# define DOWN_KEY	125	
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define W_KEY		13
# define ESC		53

typedef struct s_vector
{
	int	x;
	int	y;
}t_vector;

typedef struct s_map
{
	char		**tab;
	t_vector	size;
}t_map;

typedef struct s_img
{
	t_vector	size;
	t_vector	pos;
	char		*p_img_path;
	void		*img_path;
}t_img;

typedef struct s_game
{
	int	count_steps;
	int	count_collect;
	int	count_per;
	int	count_steps_enemy;
}t_game;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_game	game;
	t_map	map;
	t_img	img;
	t_img	enemy;
	int		there_is_enemy;
}t_var;

int		get_x_y(t_var *var, char **argv);
int		initial(t_var *var);
int		loading_map(t_var var, int row, int col);
int		print_map(t_var var);
int		read_map(t_var *var, char **argv);
int		check_argement(int argc, char **argv);
int		check_floor(t_var var);
int		check_others(t_var var);
int		check_rectangle(t_var var);
int		check_alpha_map(t_var var);
int		check_map(t_var var);
int		move_left(t_var *var);
int		move_right(t_var *var);
int		move_up(t_var *var);
int		movements(int key, t_var *var);
int		key(int key, t_var *var);
int		get_position_person(t_var *var);
int		count_collectable(t_var *var);
int		check_collectable(t_var *var);
int		free_map(t_var *var);
int		exit_free(t_var *var, char *msg);
int		step_into_enemy(int key, t_var *var);
int		check_enemy(t_var *var);
int		get_enemy_position(t_var *var);
int		enemy_move_right(t_var *var);
int		enemy_move_down(t_var *var);
int		enemy_move_left(t_var *var);
int		enemy_move_up(t_var *var);
int		enemy(t_var *var);
void	error(char *msg, t_var *var);
int		ft_exit(t_var *var);
int		count_person(t_var *var);
int		check_person(t_var *var);
#endif
