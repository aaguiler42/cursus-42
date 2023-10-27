/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:55 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/23 03:52:11 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define TYPE_FILE_READ 0
# define TYPE_FILE_WRITE 1
# define TYPE_FILE_APPEND 2
# define TYPE_COMMAND 3

typedef struct s_all {
	t_list	*commands;
	t_list	*redirects_out;
	int		have_redirects_out;
	t_list	*redirects_in;
	int		have_redirects_in;
	char	**env;
	t_list	*env_list;
}		t_all;

typedef struct s_command {
	char	*path;
	char	**args;
	int		type;
	int		fd_input;
	int		fd_output;
	char	*here_doc;
	char	*limiter;
	char	*command;
}		t_command;

void	pipex(t_list *commands);

//Utils
int		ft_count_commands(char *line);
int		ft_get_command_len(char *line, int start);
int		ft_get_commands(char *line);
int		ft_check_errors(char *line);
int		ft_init(int argc, char **argv, char **env);
char	*ft_get_line_after_redirects(char *line);

//Free
char	**ft_free_line(char *line);
void	ft_free_list(void *content);

//Trim
char	*ft_strtrim_spaces_quotes(char *s);

//Print
void	print_list(void *list);
void	print_env(void *list);

//Env
int		ft_get_env(int argc, char **argv, char **env);
char	*ft_get_env_value(char *env);
void	ft_substitute_env(void *list_elem);
int		ft_add_one_env(char *env);

//Builtins
void	ft_env(void);
void	ft_export(char *env);
void	ft_unset(char *env_name);
char	*ft_pwd(int printable);
void	ft_cd(char *path);
void	ft_echo(char **argv);

#endif
