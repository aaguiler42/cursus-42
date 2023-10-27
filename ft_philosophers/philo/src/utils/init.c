/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:47:21 by aaguiler          #+#    #+#             */
/*   Updated: 2022/07/14 15:52:40 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_one(t_philo *philo)
{
	ft_sleep(philo->vars->die_time);
	philo->vars->philo_dead = 1;
}

void	ft_eat(t_philo *philo)
{
	int	right_index_fork;

	right_index_fork = philo->index + 1;
	if (philo->index == philo->vars->n_philos - 1)
		right_index_fork = 0;
	pthread_mutex_lock(&philo->left_fork);
	ft_message(philo, 4);
	if (philo->vars->n_philos == 1)
		ft_one(philo);
	pthread_mutex_lock(&(philo->vars->philos[right_index_fork].left_fork));
	ft_message(philo, 4);
	philo->t_last_eat = ft_gt(philo->vars->start);
	ft_message(philo, 2);
	ft_sleep(philo->vars->eat_time);
	philo->times_eat += 1;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&(philo->vars->philos[right_index_fork].left_fork));
}

void	*ft_thread_loop(void *val)
{
	t_philo	*philo;

	philo = (t_philo *)val;
	if (philo->index % 2 == 0)
		ft_sleep(10);
	while (!philo->vars->philo_dead)
	{
		ft_eat(philo);
		ft_message(philo, 1);
		ft_sleep(philo->vars->sleep_time);
		ft_message(philo, 0);
	}
	return (0);
}

void	ft_init_philos(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->n_philos)
	{
		pthread_mutex_init(&(vars->philos[i].left_fork), NULL);
		vars->philos[i].vars = vars;
		vars->philos[i].index = i;
		vars->philos[i].t_last_eat = 0;
		vars->philos[i].times_eat = 0;
		i++;
	}
	i = 0;
	while (i < vars->n_philos)
	{
		pthread_create(&(vars->philos[i].thread), NULL,
			ft_thread_loop, &(vars->philos[i]));
		i++;
	}
}

int	ft_init_args(int argc, char **argv, t_vars *vars)
{
	if (!(argc == 5 || argc == 6))
	{
		printf("Invalid args");
		return (0);
	}
	vars->n_philos = ft_atoi(argv[1]);
	vars->die_time = ft_atoi(argv[2]);
	vars->eat_time = ft_atoi(argv[3]);
	vars->sleep_time = ft_atoi(argv[4]);
	vars->philo_eat = 0;
	vars->philo_dead = 0;
	vars->eat_limit = -1;
	if (argc == 6)
		vars->eat_limit = ft_atoi(argv[5]);
	vars->start = ft_gt(0);
	vars->philos = malloc(sizeof(t_philo) * vars->n_philos);
	if (!vars->philos)
		return (0);
	pthread_mutex_init(&(vars->write_mutex), NULL);
	ft_init_philos(vars);
	return (1);
}
