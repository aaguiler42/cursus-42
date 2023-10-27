/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:34:49 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/23 03:51:54 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_all	*g_all;

int	ft_init(int argc, char **argv, char **env)
{
	g_all = malloc(sizeof(t_all));
	if (!g_all)
		return (0);
	if (!ft_get_env(argc, argv, env))
		return (0);
	return (1);
}
