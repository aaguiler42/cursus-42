/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:47:33 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/16 19:01:07 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../minishell.h"
#include <unistd.h>
#include <stdlib.h>

extern t_all	*g_all;

char	*ft_path_is_ok(char *command, char *env_path)
{
	char	*path;
	char	*aux;

	aux = ft_strjoin(env_path, "/");
	if (!aux)
		return (NULL);
	path = ft_strjoin(aux, command);
	free(aux);
	if (!path)
		return (NULL);
	if (!access(path, X_OK))
		return (path);
	free(path);
	return (NULL);
}

int	ft_is_slash(size_t i, char c)
{
	(void)i;
	return (c == '/');
}

char	*ft_find_path(char *command, char **env_paths)
{
	char	**ptr;
	char	*path;

	if (ft_strsome(command, ft_is_slash))
		return (ft_strdup(command));
	ptr = env_paths;
	if (!ptr)
		return (NULL);
	path = NULL;
	while (*ptr && !path)
	{
		path = ft_path_is_ok(command, *ptr);
		ptr++;
	}
	return (path);
}

char	**ft_get_env_paths(void)
{
	t_list	*lst;
	char	*path;
	char	**paths;

	lst = ft_lstfind_fn((g_all)->env_list, "PATH=", ft_strncmp);
	if (!lst)
		return (NULL);
	path = lst->content;
	if (!path)
		return (NULL);
	paths = ft_split(path + 5, ':');
	if (paths)
		return (paths);
	return (NULL);
}
