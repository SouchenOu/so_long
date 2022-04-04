/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_person_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:33:59 by souchen           #+#    #+#             */
/*   Updated: 2022/03/27 19:28:44 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long_bonus.h"

int	move_left(t_var *var)
{
	var->map.tab[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.x -= 1;
	var->map.tab[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	var->img.p_img_path = "person.xpm";
	return (0);
}

int	move_right(t_var *var)
{
	var->map.tab[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.x += 1;
	var->map.tab[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	var->img.p_img_path = "person2.xpm";
	return (0);
}

int	move_down(t_var *var)
{
	var->map.tab[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.y += 1;
	var->map.tab[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	move_up(t_var *var)
{
	var->map.tab[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.y -= 1;
	var->map.tab[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	movements(int key, t_var *var)
{
	if ((key == A_KEY || key == LEFT_KEY)
		&& (var->map.tab[var->img.pos.y][var->img.pos.x - 1] == 'E'))
		check_collectable(var);
	else if ((key == A_KEY || key == LEFT_KEY)
		&& (var->map.tab[var->img.pos.y][var->img.pos.x - 1] != '1'))
		move_left(var);
	if ((key == D_KEY || key == RIGHT_KEY)
		&& (var->map.tab[var->img.pos.y][var->img.pos.x + 1] == 'E'))
		check_collectable(var);
	else if ((key == D_KEY || key == RIGHT_KEY)
		&& (var->map.tab[var->img.pos.y][var->img.pos.x + 1] != '1'))
		move_right(var);
	if ((key == S_KEY || key == DOWN_KEY)
		&& (var->map.tab[var->img.pos.y + 1][var->img.pos.x] == 'E'))
		check_collectable(var);
	else if ((key == S_KEY || key == DOWN_KEY)
		&& (var->map.tab[var->img.pos.y + 1][var->img.pos.x] != '1'))
		move_down(var);
	if ((key == W_KEY || key == UP_KEY)
		&& (var->map.tab[var->img.pos.y - 1][var->img.pos.x] == 'E'))
		check_collectable(var);
	else if ((key == W_KEY || key == UP_KEY)
		&& (var->map.tab[var->img.pos.y - 1][var->img.pos.x] != '1'))
		move_up(var);
	return (0);
}
