/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:10:10 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/21 23:41:42 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_var *vars, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
		mlx_put_pixel(vars->g_img, x, y, color);
}

uint32_t	ft_get_color_pix(t_var *vars, int x, int y, int dir)
{
	uint32_t	color;
	uint8_t		*pix;

	if (dir == 'N')
		pix = &(vars->t_no->pixels[64 * y * 4 + x * 4]);
	else if (dir == 'S')
		pix = &(vars->t_su->pixels[64 * y * 4 + x * 4]);
	else if (dir == 'E')
		pix = &(vars->t_es->pixels[64 * y * 4 + x * 4]);
	else
		pix = &(vars->t_we->pixels[64 * y * 4 + x * 4]);
	color = (pix[0] << 24) | (pix[1] << 16) | (pix[2] << 8) | pix[3];
	return (color);
}

void	ft_draw_vertical_line(t_var *vars, int x, t_ray *ray)
{
	int			i;
	int			y;
	t_float		t;
	int			height;
	int			dir;

	height = ray->line_h;
	dir = ray->dir;
	y = HEIGHT / 2 - height / 2;
	t.y = ray->ty_step * ray->ty_offset;
	if (ray->dir == 'N' || ray->dir == 'S')
		t.x = (int)ray->x % 64;
	else
		t.x = (int)ray->y % 64;
	i = y;
	while (i < y + height)
	{
		ft_put_pixel(vars, x, i, ft_get_color_pix(vars, t.x, t.y, dir));
		t.y += ray->ty_step;
		i++;
	}
}
