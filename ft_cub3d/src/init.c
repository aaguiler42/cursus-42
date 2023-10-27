/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:08:45 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/23 20:06:44 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_properties(t_var *vars, char **file_names, int *error)
{
	vars->ceiling = ft_get_color_property(file_names, "C", error);
	vars->floor = ft_get_color_property(file_names, "F", error);
	if (*error)
		return (ft_error("Bad color", 0));
	vars->t_no = ft_get_texture_property(file_names, "NO", error);
	vars->t_su = ft_get_texture_property(file_names, "SO", error);
	vars->t_we = ft_get_texture_property(file_names, "WE", error);
	vars->t_es = ft_get_texture_property(file_names, "EA", error);
	if (*error)
	{
		ft_free_vars(vars);
		return (ft_error("Bad texture", 1));
	}
	vars->map_data = NULL;
	ft_parse_map(file_names, vars);
	if (!vars->map_data)
	{
		ft_free_vars(vars);
		return (ft_error("Bad map", 0));
	}
	return (0);
}

void	ft_free_file(char *file, char **file_names)
{
	int	i;

	if (file)
		free(file);
	i = 0;
	while (file_names[i])
		free(file_names[i++]);
	if (file_names)
		free(file_names);
}

void	ft_set_map_x(t_var *vars, char **map)
{
	int	i;
	int	tmp;

	i = 0;
	vars->map_real.x = 0;
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp > vars->map_real.x)
			vars->map_real.x = tmp;
		i++;
	}
}

int	ft_parse(t_var *vars, int argc, char *argv[])
{
	char	*file;
	char	**file_names;
	int		error;

	if (!ft_check_args(argc, argv))
		return (1);
	file = ft_read_file(argv[1]);
	if (!file)
		return (ft_free_vars(vars), ft_error(NULL, 1));
	file_names = ft_split(file, '\n');
	if (!file_names)
		return (ft_free_file(file, file_names), ft_error(NULL, 1));
	error = 0;
	if (ft_properties(vars, file_names, &error))
		return (ft_free_file(file, file_names), ft_free_vars(vars), 1);
	if (!ft_check_map_content(vars->map_data))
		error = 1;
	if (!ft_set_player(vars))
		error = 1;
	if (!ft_check_map_wall(vars->map_data, vars->map_real.y, vars->map_real.x))
		error = 1;
	if (error)
		return (ft_free_file(file, file_names), ft_error("Bad map", 0));
	ft_free_file(file, file_names);
	return (0);
}

t_var	*ft_init_vars(int arcg, char *argv[])
{
	t_var	*vars;

	vars = ft_calloc(1, sizeof(t_var));
	if (!vars)
		exit(0);
	if (ft_parse(vars, arcg, argv))
		exit(0);
	vars->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!vars->mlx)
	{
		free(vars);
		exit(0);
	}
	vars->g_img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->map.y = vars->map_real.y * MS;
	vars->map.x = vars->map_real.x * MS;
	ft_get_angle(vars);
	return (vars);
}
