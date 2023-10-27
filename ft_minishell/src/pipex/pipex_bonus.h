/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:15:27 by narso             #+#    #+#             */
/*   Updated: 2023/01/23 03:37:02 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "../minishell.h"

// Checker
char	*ft_check_args(int argc, char **argv);

// Commands
t_list	*ft_get_commands_pipex(char **argv, int argc, char **env_paths,
			char *limiter);
void	ft_execute_command(t_list *lstcommand, char **envp);
t_list	*ft_create_command_pipex(char *argv, int type, char **env_paths,
			char *limiter);
void	ft_free_command(void *content);
void	ft_free_env_paths(char **env_paths);

// Parser
char	**ft_parse_command(char *arg);

// Exec
int		ft_exec(t_command *command, char **envp, int is_last_command);
void	ft_command_exec(t_list *lstcommand, char **envp,
			t_command *command, t_command *next_command);
void	ft_open_file_to_write(t_command *prevcommand, t_command *file);
void	ft_execute_builtin(t_command *command);
int		ft_is_builtin(char *command);
void	ft_wait_last_command(pid_t pid, int is_last_command);

// Path
char	**ft_get_env_paths(void);
char	*ft_find_path(char *command, char **env_paths);

//Utils
int		ft_is_last_command(t_list *lstcommand);

#endif
