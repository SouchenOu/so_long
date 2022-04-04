/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:55:49 by souchen           #+#    #+#             */
/*   Updated: 2022/03/27 19:26:19 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long_bonus.h"

int	animation(t_var *var)
{
	if (var->enemy.pos.x % 2 == 0)
	{
		var->img.img_path = mlx_xpm_file_to_image(var->mlx, "enemy.xpm",
				&(var->img.size.x), &(var->img.size.y));
	}
	else
	{
		var->img.img_path = mlx_xpm_file_to_image(var->mlx, "enemy2.xpm",
				&(var->img.size.x), &(var->img.size.y));
	}
	return (0);
}
