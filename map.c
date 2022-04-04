/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:31:22 by souchen           #+#    #+#             */
/*   Updated: 2022/04/04 09:32:50 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long.h"

int	get_x_y(t_var *var, char **argv)
{
	int		fd;
	char	*box;

	var->map.size.x = 0;
	var->map.size.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, Map not found\n");
		return (-1);
	}
	box = get_next_line(fd);
	while (box != NULL)
	{
		var->map.size.x = ft_strlen(box);
		var->map.size.y++;
		free(box);
		box = get_next_line(fd);
	}
	free(box);
	var->map.size.x--;
	return (0);
}

int	read_map(t_var *var, char **argv)
{
	int		ligne;
	int		fd;

	ligne = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, Map not found\n");
		return (-1);
	}
	var->map.tab[ligne] = get_next_line(fd);
	while (var->map.tab[ligne] != NULL)
	{
		ligne++;
		var->map.tab[ligne] = get_next_line(fd);
	}
	check_map(*var);
	check_person(var);
	return (0);
}

int	loading_map(t_var var, int ligne, int colone)
{
	if (var.map.tab[ligne][colone] == '1')
		var.img.img_path = mlx_xpm_file_to_image(var.mlx, "mur.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.tab[ligne][colone] == '0')
		var.img.img_path = mlx_xpm_file_to_image(var.mlx, "floor.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.tab[ligne][colone] == 'E')
		var.img.img_path = mlx_xpm_file_to_image(var.mlx, "exit.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.tab[ligne][colone] == 'C')
		var.img.img_path = mlx_xpm_file_to_image(var.mlx, "argent.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.tab[ligne][colone] == 'P')
		var.img.img_path = mlx_xpm_file_to_image(var.mlx, var.img.p_img_path,
				&var.img.size.x, &var.img.size.y);
	mlx_put_image_to_window(var.mlx, var.win, var.img.img_path,
		colone * 64, ligne * 64);
	mlx_destroy_image(var.mlx, var.img.img_path);
	return (0);
}

int	print_map(t_var var)
{
	int	ligne;
	int	colone;

	ligne = 0;
	while (ligne < var.map.size.y)
	{
		colone = 0;
		while (colone < var.map.size.x)
		{
			loading_map(var, ligne, colone);
			colone++;
		}
		ligne++;
	}
	return (0);
}

int	free_map(t_var *var)
{
	int	ligne;

	ligne = 0;
	mlx_destroy_window(var->mlx, var->win);
	while (ligne < var->map.size.y)
	{
		free(var->map.tab[ligne]);
		ligne++;
	}
	free(var->map.tab[ligne]);
	free(var->map.tab);
	exit(0);
	return (0);
}
