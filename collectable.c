/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:52:00 by souchen           #+#    #+#             */
/*   Updated: 2022/04/04 09:48:40 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long.h"

int	count_collect(t_var *var)
{
	int		ligne;
	int		colone;

	ligne = 0;
	var->game.count_collect = 0;
	while (ligne < var->map.size.y)
	{
		colone = 0;
		while (colone <= var->map.size.x)
		{
			if (var->map.tab[ligne][colone] == 'C')
				var->game.count_collect++;
			colone++;
		}
		ligne++;
	}
	return (var->game.count_collect);
}

int	check_collectable(t_var *var)
{
	if (count_collect(var) == 0)
	{
		exit_free(var, "CONGRATS\n!!!! You WON !!!!\n");
	}
	else
		ft_printf("Please, collect all diamonds!!!\n");
	return (0);
}

int	count_person(t_var *var)
{
	int	ligne;
	int	colone;

	ligne = 0;
	var->game.count_per = 0;
	while (ligne < var->map.size.y)
	{
		colone = 0;
		while (colone <= var->map.size.x)
		{
			if (var->map.tab[ligne][colone] == 'P')
				var->game.count_per++;
			colone++;
		}
		ligne++;
	}
	return (var->game.count_per);
}

int	check_person(t_var *var)
{
	if (count_person(var) > 1)
	{
		error("Error, use just one person", var);
	}
	return (0);
}
