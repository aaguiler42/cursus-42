/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:39:03 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/23 20:07:02 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_angle(t_var *vars)
{
	if (vars->dir == 'N')
		vars->p_angle = 270 * DR;
	else if (vars->dir == 'S')
		vars->p_angle = 90 * DR;
	else if (vars->dir == 'E')
		vars->p_angle = 0 * DR;
	else if (vars->dir == 'W')
		vars->p_angle = 180 * DR;
	ft_recalculate_angle(vars, 0);
}

int	ft_set_player(t_var *vars)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = -1;
	while (vars->map_data[++i])
	{
		j = 0;
		while (vars->map_data[i][j])
		{
			if (ft_strchr("NSEW", vars->map_data[i][j]))
			{
				if (found)
					return (0);
				vars->p.x = j * MS;
				vars->p.y = i * MS;
				vars->dir = vars->map_data[i][j];
				vars->map_data[i][j] = '0';
				found = 1;
			}
			j++;
		}
	}
	return (found);
}
