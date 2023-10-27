/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:07:41 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/05 18:08:30 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_terminate(t_var *vars)
{
	mlx_delete_image(vars->mlx, vars->g_img);
	mlx_terminate(vars->mlx);
	ft_free_vars(vars);
	free(vars);
}
