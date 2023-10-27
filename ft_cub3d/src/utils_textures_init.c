/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_textures_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:39:07 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/23 20:00:54 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_file_property(char **fl, char *prop, char *line)
{
	t_int	p;
	char	*tmp;

	p.y = 0;
	while (fl[p.y] && !line)
	{
		line = ft_strnstr(fl[p.y++], prop, ft_strlen(prop));
		if (line)
		{
			p.x = p.y;
			while (fl[p.x] && !ft_strnstr(fl[p.x], prop, ft_strlen(prop)))
				p.x++;
			if (fl[p.x])
				return (NULL);
		}
	}
	p.x = ft_strlen(prop);
	if (!line || !ft_isspace(line[p.x]))
		return (NULL);
	while (line[p.x] && ft_isspace(line[p.x]))
		p.x++;
	if (!line[p.x])
		return (NULL);
	tmp = ft_substr(line + p.x, 0, ft_strlen(line));
	return (ft_memset(line, ' ', ft_strlen(line)), tmp);
}

mlx_texture_t	*ft_get_texture_property(char **file_lines,
	char *property, int *error)
{
	char			*texture_path;
	mlx_texture_t	*texture;
	char			*line;

	line = NULL;
	texture_path = ft_get_file_property(file_lines, property, line);
	if (!texture_path)
	{
		*error = 1;
		return (NULL);
	}
	texture = mlx_load_png(texture_path);
	free(texture_path);
	if (!texture)
	{
		*error = 1;
		return (NULL);
	}
	return (texture);
}
