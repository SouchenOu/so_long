/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:24:14 by souchen           #+#    #+#             */
/*   Updated: 2022/04/04 09:53:41 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long_bonus.h"

int	key(int key, t_var *var)
{
	int	initial_steps;

	initial_steps = var->game.count_steps;
	if (key == ESC)
		exit_free(var, "Game closed! (ESC)\n");
	else
	{
		if (var->there_is_enemy == 1)
			step_into_enemy(key, var);
		movements(key, var);
	}
	if (var->game.count_steps != initial_steps)
		ft_printf("Steps: %d\n", var->game.count_steps);
	print_map(*var);
	return (0);
}

void	error(char *msg, t_var *var)
{
	int	ligne;

	ligne = 0;
	ft_printf("Error\t: %s\n", msg);
	while (ligne < var->map.size.y)
	{
		free(var->map.tab[ligne]);
		ligne++;
	}
	exit(EXIT_FAILURE);
}

int	ft_exit(t_var *var)
{
	free_map(var);
	return (0);
}
