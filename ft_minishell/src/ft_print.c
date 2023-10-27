/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:49:53 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/23 01:00:18 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	print_list(void *list)
{
	t_command	*command;

	command = (t_command *)list;
	printf("%s %d\n", command->command, command->type);
}

void	print_env(void *list)
{
	char	*str;

	str = (char *)list;
	if (str && str[0] && str[0] != '?')
		printf("%s\n", str);
}
