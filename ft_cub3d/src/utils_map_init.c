/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:38:54 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/23 20:04:11 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_wall(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && (i == 0 || j == 0
				|| i == height - 1 || j == width - 1
				|| !map[i + 1] || !map[i][j + 1]
				|| !map[i - 1][j] || !map[i][j - 1]
				|| ft_isspace(map[i + 1][j]) || ft_isspace(map[i][j + 1])
				|| ft_isspace(map[i - 1][j]) || ft_isspace(map[i][j - 1])
				))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_copy_map(char **fl, int i, t_var *vars)
{
	int		j;

	ft_set_map_x(vars, fl + i);
	vars->map_data = ft_calloc(vars->map_real.y + 1, sizeof(char *));
	if (!vars->map_data)
		return ;
	j = 0;
	while (fl[i])
	{
		vars->map_data[j] = ft_calloc(vars->map_real.x + 1, sizeof(char));
		ft_strlcpy(vars->map_data[j], fl[i], vars->map_real.x + 1);
		if (!vars->map_data[j])
		{
			while (j > 0)
				free(vars->map_data[--j]);
			free(vars->map_data);
			vars->map_data = NULL;
			return ;
		}
		i++;
		j++;
	}
}

void	ft_parse_map(char **fl, t_var *vars)
{
	int		i;
	int		j;

	i = -1;
	while (fl[++i])
	{
		j = 0;
		while (ft_isspace(fl[i][j]))
			j++;
		if (fl[i][j] && fl[i][j] != '1')
			return ;
		if (fl[i][j] == '1')
			break ;
	}
	if (!fl[i])
		return ;
	j = 0;
	while (fl[i + j])
		j++;
	if (j < 3)
		return ;
	vars->map_real.y = j;
	ft_copy_map(fl, i, vars);
}

int	ft_is_not_map_content(size_t idx, char c)
{
	(void)idx;
	return (!ft_strchr("01NSEW \t\n\v\f\r", c));
}

int	ft_check_map_content(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strsome(map[i], ft_is_not_map_content))
			return (0);
		i++;
	}
	return (1);
}
