/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:14:48 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/23 03:52:17 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "pipex/pipex_bonus.h"

extern t_all	*g_all;

int	ft_check_errors(char *line)
{
	int	quotes;
	int	i;

	if (line[0] == '|' || line[ft_strlen(line) - 1] == '|')
		return (0);
	quotes = 0;
	i = 0;
	while (line[i])
	{
		if ((line[i] == '\\' || line[i] == ';') && !quotes)
			return (0);
		if (line[i] == quotes)
			quotes = 0;
		else if (!quotes && ft_strchr("\"'", line[i]))
			quotes = line[i];
		if (!quotes && line[i] == '|' && line[i + 1] && line[i + 1] == '|')
			return (0);
		i++;
	}
	if (quotes)
		return (0);
	return (1);
}

int	ft_get_command_len(char *line, int start)
{
	int	quotes;
	int	i;

	quotes = 0;
	i = 0;
	while (line[start + i])
	{
		if (line[start + i] == '\"' && quotes == 0)
			quotes = 2;
		else if (line[start + i] == '\"' && quotes == 2)
			quotes = 0;
		else if (line[start + i] == '\'' && quotes == 0)
			quotes = 1;
		else if (line[start + i] == '\'' && quotes == 1)
			quotes = 0;
		if (line[start + i] == '|' && !quotes)
			break ;
		i++;
	}
	return (i);
}

t_list	*ft_create_command(char *line, int start, int len)
{
	t_command	*command;
	char		*bare_command;
	t_list		*list_aux;

	bare_command = ft_strtrim_spaces_quotes(ft_substr(line, start, len));
	if (!bare_command)
		return (NULL);
	command = (t_command *)ft_calloc(sizeof(t_command), 1);
	if (!command)
	{
		free(bare_command);
		return (NULL);
	}
	command->command = bare_command;
	list_aux = ft_lstnew(command);
	if (!list_aux)
	{
		free(command);
		free(bare_command);
		return (NULL);
	}
	return (list_aux);
}

int	ft_get_commands(char *line)
{
	t_list		*list_aux;
	int			start;
	int			len;

	line = ft_get_line_after_redirects(line);
	start = 0;
	len = 0;
	(g_all)->commands = NULL;
	while (line[start + len])
	{
		start += len;
		if (line[start] == '|')
			start++;
		len = ft_get_command_len(line, start);
		list_aux = ft_create_command(line, start, len);
		if (!list_aux)
		{
			ft_lstclear(&(g_all)->commands, ft_free_list);
			return (free(line), 0);
		}
		ft_lstadd_back(&(g_all)->commands, list_aux);
	}
	return (free(line), 1);
}
