/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nonzale <ngonzale@student.42malaga.comm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:21:13 by narso             #+#    #+#             */
/*   Updated: 2023/01/03 23:31:18 by ngonzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

extern t_all	*g_all;

void	ft_execute_commands(t_list *commands, char **envp)
{
	t_list		*cur_command;

	cur_command = commands;
	while (cur_command)
	{
		ft_execute_command(cur_command, envp);
		cur_command = cur_command->next;
	}
}

void	ft_create_commands_pipex(t_list **lst, t_list *tmp,
	t_list *tmp2, char **env_vars)
{
	if (g_all->have_redirects_in)
		*lst = g_all->redirects_in;
	else
	{
		*lst = ft_create_command_pipex((((t_command *)(tmp->content))->command),
				3, env_vars, NULL);
		tmp = tmp->next;
	}
	while (tmp)
	{
		tmp2 = ft_create_command_pipex((((t_command *)(tmp->content))->command),
				3, env_vars, NULL);
		ft_lstadd_back(lst, tmp2);
		tmp = tmp->next;
	}
	if (g_all->have_redirects_out)
	{	
		tmp = g_all->redirects_out;
		while (tmp)
		{
			ft_lstadd_back(lst, tmp);
			tmp = tmp->next;
		}
	}
}

void	pipex(t_list *commands)
{
	t_list	*lst;
	t_list	*tmp;
	t_list	*tmp2;
	char	**env_vars;

	ft_lstiter(commands, ft_substitute_env);
	env_vars = ft_get_env_paths();
	tmp = commands;
	tmp2 = NULL;
	ft_create_commands_pipex(&lst, tmp, tmp2, env_vars);
	ft_execute_commands(lst, env_vars);
	ft_lstclear(&lst, ft_free_list);
	ft_free_env_paths(env_vars);
}
