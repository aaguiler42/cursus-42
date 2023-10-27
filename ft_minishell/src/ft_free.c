/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:26:56 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/23 02:27:43 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_free_line(char *line)
{
	free(line);
	return (NULL);
}

void	ft_free_list(void *content)
{
	t_command	*command;
	int			i;

	command = (t_command *)content;
	if (command->path)
		free(command->path);
	i = 0;
	if (command->args)
	{
		while (command->args[i])
		{
			free(command->args[i]);
			i++;
		}
		free(command->args);
	}
	if (command->here_doc && command->here_doc[0])
		free (command->here_doc);
	if (command->command && command->command[0])
		free(command->command);
	free(command);
}
