/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:38:47 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/21 23:35:27 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

// void	ft_exit(void)
// {
// 	system("leaks cub3d");
// }

int32_t	main(int argc, char **argv)
{
	t_var	*vars;

	vars = ft_init_vars(argc, argv);
	ft_display(vars);
	mlx_image_to_window(vars->mlx, vars->g_img, 0, 0);
	ft_loop(vars);
	ft_terminate(vars);
	return (0);
}
