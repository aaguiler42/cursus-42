/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:17:50 by narso             #+#    #+#             */
/*   Updated: 2023/01/23 03:24:03 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

t_list	*ft_get_commands_helper(t_list **commands);

t_list	*ft_get_commands_pipex(char **argv, int argc,
	char **env_paths, char *limiter)
{
	t_list	*commands;
	t_list	*aux;
	int		i;

	commands = ft_create_command_pipex(argv[0], TYPE_FILE_READ, NULL, limiter);
	if (!commands)
		return (NULL);
	i = 0;
	while (++i < argc - 1)
	{
		aux = ft_create_command_pipex(argv[i], TYPE_COMMAND, env_paths, NULL);
		if (!aux)
			return (ft_get_commands_helper(&commands));
		ft_lstadd_back(&commands, aux);
	}
	aux = ft_create_command_pipex(argv[argc - 1], TYPE_FILE_WRITE,
			NULL, limiter);
	if (!aux)
		return (ft_get_commands_helper(&commands));
	ft_lstadd_back(&commands, aux);
	return (commands);
}

void	ft_open_file_to_read(t_list *lstcommand)
{
	t_command	*command;
	t_command	*next_command;
	int			fd;

	command = (t_command *)lstcommand->content;
	if (!lstcommand->next)
		return ;
	next_command = (t_command *)lstcommand->next->content;
	if (command->limiter)
		next_command->here_doc = command->limiter;
	else
	{
		fd = open(command->path, O_RDONLY);
		if (fd > 0)
			next_command->fd_input = fd;
		else
			perror("minishell: input");
	}
}

void	ft_open_file_to_write(t_command *prevcommand, t_command *file)
{
	int			fd;

	if (file->type == TYPE_FILE_WRITE)
		fd = open(file->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else
		fd = open(file->path, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd > 0)
		prevcommand->fd_output = fd;
	else
		perror("open");
}

void	ft_execute_command(t_list *lstcommand, char **envp)
{
	t_command	*command;
	t_command	*next_command;

	command = (t_command *)lstcommand->content;
	next_command = NULL;
	if (lstcommand->next)
		next_command = (t_command *)lstcommand->next->content;
	if (command->type == TYPE_FILE_READ)
		ft_open_file_to_read(lstcommand);
	else if (command->type == TYPE_COMMAND)
		ft_command_exec(lstcommand, envp, command, next_command);
}

t_list	*ft_get_commands_helper(t_list **commands)
{
	ft_lstclear(commands, ft_free_command);
	return (NULL);
}
