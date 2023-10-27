/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:41:04 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/23 17:09:19 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

__uint32_t	ft_get_color(char *color, int *error)
{
	char		**color_split;
	__uint32_t	color_int;
	int			i;

	color_split = ft_split(color, ',');
	if (!color_split)
		*error = 1;
	if (!color_split)
		return (0);
	i = 0;
	color_int = 0;
	while (color_split[i])
	{
		color_int = color_int << 8;
		color_int += ft_atoic(color_split[i], error);
		free(color_split[i]);
		i++;
	}
	free(color_split);
	if (i != 3 || *error)
		*error = 1;
	if (i != 3 || *error)
		return (0);
	return ((color_int << 8) + 255);
}

__uint32_t	ft_get_color_property(char **file_lines, char *property, int *error)
{
	char		*color;
	__uint32_t	color_int;
	char		*line;

	line = NULL;
	color = ft_get_file_property(file_lines, property, line);
	if (!color || color[ft_strlen(color) - 1] == ',')
	{
		*error = 1;
		return (0);
	}
	color_int = ft_get_color(color, error);
	free(color);
	if (*error)
		return (0);
	return (color_int);
}
