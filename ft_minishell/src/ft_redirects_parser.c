/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirects_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:00:50 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/23 01:53:27 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "pipex/pipex_bonus.h"

extern t_all	*g_all;

char	*ft_out_redirection(int redirect_type, int i, char *line)
{
	char	*redirection;
	char	*red_wout_spa;
	char	**paths;
	char	*new_line;
	int		j;

	j = 0;
	while (line[i + j + 1] && line[i + j + 1] == ' ')
		j++;
	while (line[i + j + 1] && line[i + j + 1] != ' ')
		j++;
	while (line[i + j + 2] && line[i + j + 2] == ' ')
		j++;
	new_line = ft_strjoin(ft_substr(line, 0, i - redirect_type),
			ft_substr(line, i + j + 1, ft_strlen(line) - i - j - 1));
	redirection = ft_substr(line, i, j + 1);
	red_wout_spa = ft_strtrim_spaces_quotes(redirection);
	paths = ft_get_env_paths();
	(g_all)->redirects_out = ft_create_command_pipex(red_wout_spa,
			redirect_type, paths, NULL);
	free(line);
	ft_free_strs(paths);
	return (new_line);
}

char	*ft_in_redirection(int redirect_type, int i, char *line, int heredoc)
{
	char	*redirection;
	char	*red_wout_spa;
	char	*new_line;
	char	**paths;
	int		j;

	j = 0;
	while (line[i + j + 1] && line[i + j + 1] == ' ')
		j++;
	while (line[i + j + 1] && line[i + j + 1] != ' ')
		j++;
	while (line[i + j + 2] && line[i + j + 2] == ' ')
		j++;
	new_line = ft_strjoin(ft_substr(line, 0, i - 1 - heredoc),
			ft_substr(line, i + j + 1, ft_strlen(line) - i - j - 1));
	redirection = ft_substr(line, i, j + 1);
	red_wout_spa = ft_strtrim_spaces_quotes(redirection);
	paths = ft_get_env_paths();
	if (!heredoc)
		(g_all)->redirects_in = ft_create_command_pipex(red_wout_spa,
				redirect_type, paths, NULL);
	else
		(g_all)->redirects_in = ft_create_command_pipex(red_wout_spa,
				redirect_type, paths, ft_strdup(red_wout_spa));
	return (free(line), ft_free_strs(paths), new_line);
}

int	ft_get_redirect_type_out(char *line, int *i)
{
	(*i)++;
	if (line[*i] == '>')
	{
		(*i)++;
		return (TYPE_FILE_APPEND);
	}
	return (TYPE_FILE_WRITE);
}

int	ft_get_redirect_type_in(char *line, int *i, int *heredoc)
{
	(*i)++;
	if (line[*i] == '<')
	{
		(*i)++;
		*heredoc = 1;
	}
	else
		*heredoc = 0;
	return (TYPE_FILE_READ);
}

char	*ft_get_line_after_redirects(char *line)
{
	int		i;
	int		redirect_type;
	int		heredoc;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '>' || line[i] == '<')
		{
			if (line[i] == '>')
			{
				redirect_type = ft_get_redirect_type_out(line, &i);
				line = ft_out_redirection(redirect_type, i, line);
				(g_all)->have_redirects_out = 1;
			}
			else
			{
				redirect_type = ft_get_redirect_type_in(line, &i, &heredoc);
				line = ft_in_redirection(redirect_type, i, line, heredoc);
				(g_all)->have_redirects_in = 1;
			}
			i = -1;
		}
	}
	return (line);
}
