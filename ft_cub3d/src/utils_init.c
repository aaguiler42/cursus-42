/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:08:45 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/23 17:45:32 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_args(int argc, char **argv)
{
	char	*extension;
	size_t	arg_len;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nMap filename required\n", 2);
		return (0);
	}
	arg_len = ft_strlen(argv[1]);
	if (arg_len < 4)
	{
		ft_putstr_fd("Error\nBad filename\n", 2);
		return (0);
	}
	extension = ft_substr(argv[1], arg_len - 4, arg_len);
	if (!extension)
		return (0);
	if (ft_strncmp(".cub", extension, ft_strlen(extension)))
	{
		free(extension);
		ft_putstr_fd("Error\nBad filename\n", 2);
		return (0);
	}
	free(extension);
	return (1);
}

int	ft_error(char *message, int print_strerror)
{
	ft_putstr_fd("Error\n", 2);
	if (message)
	{
		ft_putstr_fd(message, 2);
		if (print_strerror && errno)
			ft_putstr_fd(": ", 2);
		else
			ft_putstr_fd("\n", 2);
	}
	if (print_strerror && errno)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	return (1);
}

void	ft_free_vars(t_var *vars)
{
	int	i;

	if (vars->t_no)
		mlx_delete_texture(vars->t_no);
	if (vars->t_su)
		mlx_delete_texture(vars->t_su);
	if (vars->t_we)
		mlx_delete_texture(vars->t_we);
	if (vars->t_es)
		mlx_delete_texture(vars->t_es);
	vars->t_no = NULL;
	vars->t_su = NULL;
	vars->t_we = NULL;
	vars->t_es = NULL;
	if (vars->map_data)
	{
		i = 0;
		while (vars->map_data[i])
		{
			free(vars->map_data[i]);
			i++;
		}
		free(vars->map_data);
	}
}
