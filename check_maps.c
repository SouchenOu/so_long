/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:37:45 by souchen           #+#    #+#             */
/*   Updated: 2022/04/04 09:32:29 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long.h"

int	check_floor(t_var var)
{
	int	ligne;
	int	colone;

	ligne = 0;
	while (ligne < var.map.size.y)
	{
		colone = 0;
		if (ligne == 0 || ligne == (var.map.size.y - 1))
		{
			while (var.map.tab[ligne][colone] != '\n')
			{
				if (var.map.tab[ligne][colone] != '1')
					error("Top or,down wall not configured\n", &var);
				colone++;
			}
		}
		if (var.map.tab[ligne][0] != '1'
			|| var.map.tab[ligne][var.map.size.x - 1] != '1')
			error("Lateral wall not configured\n", &var);
		ligne++;
	}
	return (0);
}

int	check_others(t_var var)
{
	char	box[4];
	int		ligne;
	int		colone;

	ligne = 0;
	while (ligne < var.map.size.y)
	{
		colone = 0;
		while (colone <= var.map.size.x)
		{
			if (var.map.tab[ligne][colone] == 'P')
				box[0] = 1;
			if (var.map.tab[ligne][colone] == 'E')
				box[1] = 1;
			if (var.map.tab[ligne][colone] == 'C')
				box[2] = 1;
			colone++;
		}
		ligne++;
	}
	if (box[0] != 1 || box[1] != 1 || box[2] != 1)
		error("Missing one of this: person,Exit or collectable\n", &var);
	return (0);
}

int	check_rectangle(t_var var)
{
	int	ligne;

	ligne = 0;
	while (ligne < var.map.size.y)
	{
		if (var.map.size.x + 1 != (int)ft_strlen(var.map.tab[ligne]))
			error("Not a retangle\n", &var);
		ligne++;
	}
	return (0);
}

int	check_alpha_map(t_var var)
{
	int	ligne;
	int	colone;

	ligne = 0;
	while (ligne < var.map.size.y)
	{
		colone = 0;
		while (var.map.tab[ligne][colone] != '\n')
		{
			if (var.map.tab[ligne][colone] != '0'
					&& var.map.tab[ligne][colone] != '1'
					&& var.map.tab[ligne][colone] != 'P'
					&& var.map.tab[ligne][colone] != 'C'
					&& var.map.tab[ligne][colone] != 'E')
				error("Unknown alpha\n", &var);
			colone++;
		}
		ligne++;
	}
	return (0);
}

int	check_map(t_var var)
{
	check_floor(var);
	check_others(var);
	check_rectangle(var);
	check_alpha_map(var);
	return (0);
}
