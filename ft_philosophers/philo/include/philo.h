/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:06:54 by aaguiler          #+#    #+#             */
/*   Updated: 2022/07/14 15:29:50 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_vars	t_vars;

typedef struct s_philo
{
	t_vars			*vars;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	int				index;
	int				times_eat;
	uint64_t		t_last_eat;
}	t_philo;

typedef struct s_vars
{
	uint64_t		start;
	int				n_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_limit;
	int				philo_dead;
	int				philo_eat;
	pthread_mutex_t	write_mutex;
	t_philo			*philos;
}	t_vars;

//Utils
int			ft_atoi(const char *str);
void		ft_message(t_philo *philo, int cod);

//Init utils
void		*ft_thread_loop(void *val);
void		ft_init_philos(t_vars *vars);
int			ft_init_args(int argc, char **argv, t_vars *vars);

//Time utils
uint64_t	ft_gt(uint64_t init);
void		ft_sleep(uint64_t time_2_sleep);

#endif