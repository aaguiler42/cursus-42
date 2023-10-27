/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:51:13 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/07 17:15:17 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_safe_float_sum(float a, float b)
{
	float	c;

	c = a + b;
	if (c < 0)
		c += 2 * PI;
	if (c > 2 * PI)
		c -= 2 * PI;
	return (c);
}

void	ft_recalculate_angle(t_var *vars, float variation)
{
	vars->p_angle = ft_safe_float_sum(vars->p_angle, variation);
	vars->pd.x = cos(vars->p_angle) * 5;
	vars->pd.y = sin(vars->p_angle) * 5;
	ft_display(vars);
}

void	ft_move_player(t_var *vars, int x, int y)
{
	vars->p.x += x;
	vars->p.y += y;
	ft_display(vars);
}

int	ft_is_minimap(t_var *vars, t_point p)
{
	if (p.x <= vars->map_real.x * 10 && p.y <= vars->map_real.y * 10)
		return (1);
	return (0);
}

float	dist(t_point a, t_ray b)
{
	float	dx;
	float	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	return (sqrt(dx * dx + dy * dy));
}
