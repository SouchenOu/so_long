/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:36:42 by souchen           #+#    #+#             */
/*   Updated: 2022/04/04 09:51:09 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long.h"

int	key(int key, t_var *var)
{
	int	initial_steps;

	initial_steps = var->game.count_steps;
	if (key == ESC)
		exit_free(var, "Game closed! (ESC)\n");
	else
		movements(key, var);
	if (var->game.count_steps != initial_steps)
		ft_printf("Steps: %d\n", var->game.count_steps);
	print_map(*var);
	return (0);
}

void	error(char *msg, t_var *var)
{
	int	ligne;

	ligne = 0;
	ft_printf("Error\t: %s", msg);
	while (ligne < var->map.size.y)
	{
		free(var->map.tab[ligne]);
		ligne++;
	}
	free(var->map.tab);
	exit(EXIT_FAILURE);
}

int	ft_exit(t_var *var)
{
	free_map(var);
	return (0);
}
