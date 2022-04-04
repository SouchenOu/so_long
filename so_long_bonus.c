/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:51 by souchen           #+#    #+#             */
/*   Updated: 2022/04/04 09:54:19 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/so_long_bonus.h"

int	initial(t_var *var)
{
	var->map.tab = malloc((var->map.size.y + 1) * sizeof(char *));
	var->map.tab[var->map.size.y] = NULL;
	var->game.count_steps = 0;
	var->game.count_steps_enemy = 0;
	var->enemy.pos.x = 0;
	var->enemy.pos.y = 0;
	var->there_is_enemy = 0;
	var->img.p_img_path = "person_won.xpm";
	return (0);
}

int	check_argement(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error :Provide map name and extension as argument\n");
		return (-1);
	}
	if (argc > 2)
	{
		ft_printf("Error :Too many arguments\n");
		return (-1);
	}
	if (ft_strnstr(&(argv[1][ft_strlen(argv[1]) - 4]), ".ber", 4) == NULL)
	{
		ft_printf("Error :Invalid map extension. Use .ber\n");
		return (-1);
	}
	return (0);
}

int	get_position_person(t_var *var)
{
	int	ligne;
	int	colone;

	ligne = 0;
	while (ligne < var->map.size.y)
	{
		colone = 0;
		while (colone <= var->map.size.x)
		{
			if (var->map.tab[ligne][colone] == 'P')
			{
				var->img.pos.x = colone;
				var->img.pos.y = ligne;
			}
			colone++;
		}
		ligne++;
	}
	return (0);
}

int	exit_free(t_var *var, char *msg)
{
	ft_printf("%s\n", msg);
	free_map(var);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;

	if (check_argement(argc, argv) == -1)
		return (-1);
	if (get_x_y(&var, argv) == -1)
		return (-1);
	initial(&var);
	read_map(&var, argv);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.map.size.x * 64,
			var.map.size.y * 64, "So long");
	print_map(var);
	get_position_person(&var);
	check_enemy(&var);
	if (var.there_is_enemy != 1)
		exit_free(&var, "You can use just one enemy!/ put just one enemy!");
	mlx_hook(var.win, 2, 1L << 2, key, &var);
	if (var.there_is_enemy == 1)
		mlx_loop_hook(var.mlx, enemy, &var);
	mlx_hook(var.win, 17, 0, ft_exit, &var);
	mlx_loop(var.mlx);
}
