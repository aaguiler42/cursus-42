/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:56:38 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/23 03:36:52 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_is_last_command(t_list *lstcommand)
{
	t_list		*aux;
	t_command	*command;

	aux = lstcommand->next;
	while (aux)
	{
		command = aux->content;
		if (command->type == TYPE_COMMAND)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	ft_command_exec(t_list *lstcommand, char **envp,
	t_command *command, t_command *next_command)
{
	int			is_last_command;
	int			buffer;
	int			written;

	is_last_command = ft_is_last_command(lstcommand);
	if (next_command && (next_command->type == TYPE_FILE_WRITE
			|| next_command->type == TYPE_FILE_APPEND))
	{
		ft_open_file_to_write(command, next_command);
		ft_exec(command, envp, is_last_command);
	}
	else if (next_command && next_command->type == TYPE_COMMAND)
	{
		command->fd_output = -1;
		next_command->fd_input = ft_exec(command, envp, is_last_command);
	}
	else
	{
		buffer = ft_exec(command, envp, is_last_command);
		while (read(buffer, &written, 1) > 0)
			write(1, &written, 1);
		close(buffer);
	}
}

int	ft_is_builtin(char *command)
{
	if (!ft_strcmp(command, "echo"))
		return (1);
	if (!ft_strcmp(command, "cd"))
		return (0);
	if (!ft_strcmp(command, "pwd"))
		return (1);
	if (!ft_strcmp(command, "export"))
		return (0);
	if (!ft_strcmp(command, "unset"))
		return (0);
	if (!ft_strcmp(command, "env"))
		return (1);
	if (!ft_strcmp(command, "exit"))
		return (0);
	return (-1);
}

void	ft_execute_builtin(t_command *command)
{
	if (!ft_strcmp(command->args[0], "echo"))
		ft_echo(command->args);
	if (!ft_strcmp(command->args[0], "cd"))
		ft_cd(command->args[1]);
	if (!ft_strcmp(command->args[0], "pwd"))
		ft_pwd(1);
	if (!ft_strcmp(command->args[0], "export"))
		ft_export(command->args[1]);
	if (!ft_strcmp(command->args[0], "unset"))
	{
		ft_unset(command->args[1]);
	}
	if (!ft_strcmp(command->args[0], "env"))
		ft_env();
	if (!ft_strcmp(command->args[0], "exit"))
	{
		if (command->args[1])
			exit(ft_atoi(command->args[1]));
		else
			exit(0);
	}
}

void	ft_wait_last_command(pid_t pid, int is_last_command)
{
	int		status;
	char	*aux;

	if (is_last_command)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			aux = ft_itoa(WEXITSTATUS(status));
			ft_export(ft_strjoin("?=", aux));
		}
	}
}
