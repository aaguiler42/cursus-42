/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:00:35 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/23 03:58:57 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_all	*g_all;

void	ft_env(void)
{
	ft_lstiter((g_all)->env_list, print_env);
}

void	ft_export(char *env)
{
	char	*previous_value;
	char	*var_name;

	if (!env)
		return ;
	if (ft_strchr(env, '=') == NULL)
	{
		printf("minishell: export: `%s': not a valid identifier\n", env);
		return ;
	}
	var_name = ft_substr(env, 0, ft_strchr(env, '=') - env);
	if (!var_name)
		return ;
	previous_value = ft_get_env_value(var_name);
	if (!previous_value)
	{
		free(var_name);
		ft_add_one_env(env);
	}
	else
	{
		ft_unset(var_name);
		ft_export(env);
		return ;
	}
}

void	ft_unset(char *env_name)
{
	char	*previous_value;
	char	*aux;
	char	*full_env;

	if (!env_name)
		return ;
	previous_value = ft_get_env_value(env_name);
	if (!previous_value)
	{
		printf("minishell: unset: `%s': not a valid identifier\n", env_name);
		return ;
	}
	aux = ft_strjoin(env_name, "=");
	if (!aux)
	{
		free(previous_value);
		return ;
	}
	full_env = ft_strjoin(aux, previous_value);
	free(aux);
	free(previous_value);
	if (!full_env)
		return ;
	ft_list_remove_if(&(g_all)->env_list, full_env, ft_strcmp);
	free(full_env);
}
