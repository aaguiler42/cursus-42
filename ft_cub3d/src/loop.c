/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:05:21 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/05 18:24:07 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_loop(t_var *vars)
{
	mlx_loop_hook(vars->mlx, &hook, vars);
	mlx_cursor_hook(vars->mlx, &my_curhook, vars);
	mlx_loop(vars->mlx);
}
