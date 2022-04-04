/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:22:47 by souchen           #+#    #+#             */
/*   Updated: 2022/03/27 19:26:33 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long_bonus.h"

int	step_into_enemy(int key, t_var *var)
{
	if ((key == A_KEY || key == LEFT_KEY)
		&& (var->map.tab[var->img.pos.y][var->img.pos.x - 1] == 'N'))
		exit_free(var, "GAME OVER\n!!!! You LOST !!!!\n");
	if ((key == D_KEY || key == RIGHT_KEY)
		&& (var->map.tab[var->img.pos.y][var->img.pos.x + 1] == 'N'))
		exit_free(var, "GAME OVER\n!!!! You LOST !!\n");
	if ((key == S_KEY || key == DOWN_KEY)
		&& (var->map.tab[var->img.pos.y + 1][var->img.pos.x] == 'N'))
		exit_free(var, "GAME OVER\n!!!! You LOST !!!!\n");
	if ((key == W_KEY || key == UP_KEY)
		&& (var->map.tab[var->img.pos.y - 1][var->img.pos.x] == 'N'))
		exit_free(var, "GAME OVER\n!!!! You LOST !!\n");
	return (0);
}

int	check_enemy(t_var *var)
{
	int	ligne;
	int	colone;

	ligne = 0;
	while (ligne < var->map.size.y)
	{
		colone = 0;
		while (var->map.tab[ligne][colone])
		{
			if (var->map.tab[ligne][colone] == 'N')
				var->there_is_enemy++;
			colone++;
		}
		ligne++;
	}
	return (0);
}

int	get_enemy_position(t_var *var)
{
	int	ligne;
	int	colone;

	ligne = 0;
	while (ligne < var->map.size.y)
	{
		colone = 0;
		while (colone <= var->map.size.x)
		{
			if (var->map.tab[ligne][colone] == 'N')
			{
				var->enemy.pos.x = colone;
				var->enemy.pos.y = ligne;
			}
			colone++;
		}
		ligne++;
	}
	return (0);
}
