/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:16:53 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/23 03:37:28 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pipex_bonus.h"

extern t_all	*g_all;

void	ft_modify_fd(t_command *command,
			int ptc[2], int ctp[2], int is_last_command)
{
	close(ptc[1]);
	close(ctp[0]);
	if (command->fd_input > 1)
		dup2(command->fd_input, STDIN_FILENO);
	else if (command->here_doc)
		dup2(ptc[0], STDIN_FILENO);
	if (command->fd_output > 1)
		dup2(command->fd_output, STDOUT_FILENO);
	else if (!is_last_command)
		dup2(ctp[1], STDOUT_FILENO);
}

void	ft_exec_child(t_command *command, char **envp)
{
	if (ft_is_builtin(command->args[0]) == 1)
	{
		ft_execute_builtin(command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (!command->path)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(command->args[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			command->path = ft_strdup("");
		}
		execve(command->path, command->args, envp);
	}
	exit(EXIT_FAILURE);
}

void	ft_exec_parent(t_command *command, int ptc[2], int ctp[2])
{
	char	*line;

	if (command->here_doc)
	{
		line = get_next_line(STDIN_FILENO);
		while (line && (ft_strncmp(command->here_doc, line, ft_strlen(line) - 1)
				|| ft_strlen(command->here_doc) != ft_strlen(line) - 1))
		{
			ft_putstr_fd(line, ptc[1]);
			free(line);
			line = get_next_line(STDIN_FILENO);
		}
		if (line)
			free(line);
	}
	close(ptc[1]);
	close(ptc[0]);
	close(ctp[1]);
}

pid_t	ft_pipe_fd(int ptc[2], int ctp[2])
{
	pid_t	pid;

	if (pipe(ptc) == -1)
		return (-1);
	if (pipe(ctp) == -1)
		return (-1);
	pid = fork();
	return (pid);
}

int	ft_exec(t_command *command, char **envp, int is_last_command)
{
	pid_t	pid;
	int		ptc[2];
	int		ctp[2];

	if (ft_is_builtin(command->args[0]) == 0)
		return (ft_execute_builtin(command), -1);
	pid = ft_pipe_fd(ptc, ctp);
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		ft_modify_fd(command, ptc, ctp, is_last_command);
		ft_exec_child(command, envp);
	}
	else
		ft_exec_parent(command, ptc, ctp);
	ft_wait_last_command(pid, is_last_command);
	return (ctp[0]);
}
