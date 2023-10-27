/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:05:42 by aaguiler          #+#    #+#             */
/*   Updated: 2022/07/14 15:50:13 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait_and_dead(t_vars *v)
{
	int	i;
	int	cont;

	cont = 0;
	while (v->philo_dead == 0 && cont != v->n_philos)
	{
		cont = 0;
		i = 0;
		while (i < v->n_philos)
		{
			if ((int)(ft_gt(v->start) - v->philos[i].t_last_eat) > v->die_time)
			{
				ft_message(&(v->philos[i]), 3);
				v->philo_dead = 1;
				break ;
			}
			if (v->philos[i].times_eat >= v->eat_limit && v->eat_limit != -1)
				cont++;
			i++;
		}
		if (cont == v->n_philos)
			pthread_mutex_lock(&(v->write_mutex));
		ft_sleep(1);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	if (!ft_init_args(argc, argv, &vars))
		return (0);
	ft_wait_and_dead(&vars);
	i = 0;
	while (i < vars.n_philos)
		pthread_mutex_destroy(&(vars.philos[i++].left_fork));
	free(vars.philos);
}
