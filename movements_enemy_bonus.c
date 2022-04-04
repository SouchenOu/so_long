/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_enemy_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:28:21 by souchen           #+#    #+#             */
/*   Updated: 2022/03/29 08:51:46 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long_bonus.h"

int	enemy_move_right(t_var *var)
{
	if (var->map.tab[var->enemy.pos.y][var->enemy.pos.x + 1] == 'P')
		exit_free(var, "GAME OVER YOU LOST !\n");
	var->map.tab[var->enemy.pos.y][var->enemy.pos.x] = '0';
	var->enemy.pos.x += 1;
	var->map.tab[var->enemy.pos.y][var->enemy.pos.x] = 'N';
	var->game.count_steps_enemy++;
	return (0);
}

int	enemy_move_down(t_var *var)
{
	if (var->map.tab[var->enemy.pos.y + 1][var->enemy.pos.x] == 'P')
		exit_free(var, "GAME OVER YOU LOST!!\n");
	var->map.tab[var->enemy.pos.y][var->enemy.pos.x] = '0';
	var->enemy.pos.y += 1;
	var->map.tab[var->enemy.pos.y][var->enemy.pos.x] = 'N';
	var->game.count_steps_enemy++;
	return (0);
}

int	enemy_move_left(t_var *var)
{
	if (var->map.tab[var->enemy.pos.y][var->enemy.pos.x - 1] == 'P')
		exit_free(var, "GAME OVER YOU LOST\n");
	var->map.tab[var->enemy.pos.y][var->enemy.pos.x] = '0';
	var->enemy.pos.x -= 1;
	var->map.tab[var->enemy.pos.y][var->enemy.pos.x] = 'N';
	var->game.count_steps_enemy++;
	return (0);
}

int	enemy_move_up(t_var *var)
{
	if (var->map.tab[var->enemy.pos.y - 1][var->enemy.pos.x] == 'P')
		exit_free(var, "GAME OVER YOU LOST\n");
	var->map.tab[var->enemy.pos.y][var->enemy.pos.x] = '0';
	var->enemy.pos.y -= 1;
	var->map.tab[var->enemy.pos.y][var->enemy.pos.x] = 'N';
	var->game.count_steps_enemy++;
	return (0);
}

int	enemy(t_var *var)
{
	usleep(200000);
	get_enemy_position(var);
	if ((var->map.tab[var->enemy.pos.y][var->enemy.pos.x + 1] == '0'
		|| var->map.tab[var->enemy.pos.y][var->enemy.pos.x + 1] == 'P')
			&& var->game.count_steps_enemy < var->map.size.x)
		enemy_move_right(var);
	else if ((var->map.tab[var->enemy.pos.y + 1][var->enemy.pos.x] == '0'
		|| var->map.tab[var->enemy.pos.y + 1][var->enemy.pos.x] == 'P')
			&& var->game.count_steps_enemy < (var->map.size.x))
		enemy_move_down(var);
	else if ((var->map.tab[var->enemy.pos.y][var->enemy.pos.x - 1] == '0'
		|| var->map.tab[var->enemy.pos.y][var->enemy.pos.x - 1] == 'P')
			&& var->game.count_steps_enemy < ((var->map.size.x)))
		enemy_move_left(var);
	else if ((var->map.tab[var->enemy.pos.y - 1][var->enemy.pos.x] == '0'
		|| var->map.tab[var->enemy.pos.y - 1][var->enemy.pos.x] == 'P')
			&& var->game.count_steps_enemy < (var->map.size.x))
		enemy_move_up(var);
	var->game.count_steps_enemy = 0;
	print_map(*var);
	print_steps(var);
	return (0);
}
