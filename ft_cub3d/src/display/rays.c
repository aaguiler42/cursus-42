/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:39:55 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/23 12:37:10 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_final_ray(t_var *vars, t_ray *ray, t_float offset)
{
	int		dof;
	t_point	m;
	int		i;

	i = vars->map_real.x;
	if (vars->map_real.y > vars->map_real.x)
		i = vars->map_real.y;
	dof = 0;
	while (dof < i)
	{
		m.x = ray->x / MS;
		m.y = ray->y / MS;
		if (m.y < vars->map_real.y && m.x < vars->map_real.x && m.x >= 0
			&& m.y >= 0 && vars->map_data[m.y][m.x] == '1')
			dof = i;
		else
		{
			ray->x += offset.x;
			ray->y += offset.y;
			dof += 1;
		}
	}
	ray->distance = dist(vars->p, *ray);
}

t_ray	*ft_horizontal_ray(t_var *vars, float r_angle)
{
	float	a_tan;
	t_float	offset;
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	a_tan = -1 / tan(r_angle);
	ray->dir = 'N';
	if (sin(r_angle) > 0)
		ray->dir = 'S';
	if (r_angle > PI)
	{
		ray->y = ((vars->p.y / MS) * MS) - 0.0001;
		offset.y = -MS;
	}
	if (r_angle < PI)
	{
		ray->y = ((vars->p.y / MS) * MS) + MS;
		offset.y = MS;
	}
	ray->x = (vars->p.y - ray->y) * a_tan + vars->p.x;
	offset.x = -offset.y * a_tan;
	if (r_angle == 0 || r_angle == PI)
		ray->distance = -1;
	ft_get_final_ray(vars, ray, offset);
	return (ray);
}

t_ray	*ft_vertical_ray(t_var *vars, float r_angle)
{
	float	n_tan;
	t_float	offset;
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	n_tan = -tan(r_angle);
	ray->dir = 'W';
	if (cos(r_angle) > 0)
		ray->dir = 'E';
	if (r_angle > P2 && r_angle < P3)
	{
		ray->x = ((vars->p.x / MS) * MS) - 0.0001;
		offset.x = -MS;
	}
	if (r_angle < P2 || r_angle > P3)
	{
		ray->x = ((vars->p.x / MS) * MS) + MS;
		offset.x = MS;
	}
	ray->y = (vars->p.x - ray->x) * n_tan + vars->p.y;
	offset.y = -offset.x * n_tan;
	if (r_angle == P2 || r_angle == P3)
		ray->distance = -1;
	ft_get_final_ray(vars, ray, offset);
	return (ray);
}

t_ray	*ft_display_one_ray(t_var *vars, float r_angle)
{
	t_ray	*ray_h;
	t_ray	*ray_v;
	t_ray	*ray;

	ray_h = ft_horizontal_ray(vars, r_angle);
	ray_v = ft_vertical_ray(vars, r_angle);
	if (ray_h->distance < ray_v->distance && ray_h->distance != -1)
		ray = ray_h;
	else
		ray = ray_v;
	if (ray_h->distance < ray_v->distance && ray_h->distance != -1)
		free(ray_v);
	else
		free(ray_h);
	ray->distance *= cos(ft_safe_float_sum(vars->p_angle, -r_angle));
	ray->line_h = (MS * HEIGHT) / ray->distance;
	ray->ty_offset = 0;
	ray->ty_step = 64.0 / (float)ray->line_h;
	if (ray->line_h > HEIGHT)
	{
		ray->ty_offset = (ray->line_h - HEIGHT) / 2.0;
		ray->line_h = HEIGHT;
	}
	ray->ray_angle = r_angle;
	return (ray);
}

void	ft_display_rays(t_var *vars)
{
	int		r;
	float	r_angle;
	t_ray	*ray;

	r = 0;
	r_angle = ft_safe_float_sum(vars->p_angle, -30 * DR);
	while (r < WIDTH)
	{
		ray = ft_display_one_ray(vars, r_angle);
		ft_draw_vertical_line(vars, r, ray);
		r_angle = ft_safe_float_sum(r_angle, DR / 16);
		free(ray);
		r++;
	}
}
