/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:38:26 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/23 13:41:51 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hook_helper_angle(t_var *vars)
{
	if (vars->mouse_x < WIDTH / 2 - 150 && vars->mouse_x > 0)
		ft_recalculate_angle(vars, -0.018);
	if (vars->mouse_x > WIDTH / 2 + 150 && vars->mouse_x < WIDTH)
		ft_recalculate_angle(vars, 0.018);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
		ft_recalculate_angle(vars, -0.022);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
		ft_recalculate_angle(vars, 0.022);
}

void	ft_hook_helper_movement(t_var *vars)
{
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W)
		&& vars->map_data[(int)(vars->p.y + vars->pd.y * 10) / MS]
		[(int)(vars->p.x + vars->pd.x * 10) / MS] != '1')
		ft_move_player(vars, vars->pd.x, vars->pd.y);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_S)
		&& vars->map_data[(int)(vars->p.y - vars->pd.y) / MS][(int)(vars->p.x
		- vars->pd.x) / MS] != '1')
		ft_move_player(vars, -vars->pd.x, -vars->pd.y);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A)
		&& vars->map_data[(int)(vars->p.y - vars->pd.x) / MS][(int)(vars->p.x
		+ vars->pd.y) / MS] != '1')
		ft_move_player(vars, vars->pd.y, -vars->pd.x);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D)
		&& vars->map_data[(int)(vars->p.y + vars->pd.x) / MS][(int)(vars->p.x
		- vars->pd.y) / MS] != '1')
		ft_move_player(vars, -vars->pd.y, vars->pd.x);
}

void	hook(void *param)
{
	t_var	*vars;

	vars = param;
	ft_hook_helper_angle(vars);
	ft_hook_helper_movement(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
}

void	my_curhook(double xpos, double ypos, void *param)
{
	t_var	*vars;

	(void)ypos;
	vars = (t_var *)param;
	vars->mouse_x = xpos;
}
