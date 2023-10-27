/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/23 03:52:02 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

t_all	*g_all = NULL;

void	c_handler(int dummy)
{
	(void)dummy;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	ft_no_heredoc(char *line)
{
	int	i;

	i = 0;
	while (line[i + 1])
	{
		if (line[i] == '<' && line[i + 1] == '<')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_get_line(void)
{
	char	*line;

	line = readline("[JUAN]~ ");
	if (!line)
		return (NULL);
	line = ft_strtrim_spaces_quotes(line);
	if (!line)
		return (NULL);
	if (line[0] != '\0' && ft_no_heredoc(line))
		add_history(line);
	if (!ft_check_errors(line))
	{
		free(line);
		line = ft_strdup("Syntax error");
	}
	(g_all)->have_redirects_out = 0;
	(g_all)->have_redirects_in = 0;
	return (line);
}

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

int	main(int argc, char **argv, char **env)
{
	char	*line;

	if (!ft_init(argc, argv, env))
		return (1);
	signal(SIGINT, c_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = ft_get_line();
		if (!line)
			break ;
		if (!ft_get_commands(line) && line[0])
			break ;
		if ((g_all)->commands)
			pipex((g_all)->commands);
		ft_lstclear(&((g_all)->commands), ft_free_list);
		(g_all)->commands = NULL;
	}
	clear_history();
}
