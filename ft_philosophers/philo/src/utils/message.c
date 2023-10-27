/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:08:49 by aaguiler          #+#    #+#             */
/*   Updated: 2022/07/14 14:55:52 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
* 0 Think
* 1 Sleep
* 2 Eat
* 3 Died
* 4 Fork
*/

void	ft_message(t_philo *philo, int cod)
{
	pthread_mutex_lock(&(philo->vars->write_mutex));
	if (cod == 0)
		printf("%llu %d is thinking\n",
			ft_gt(philo->vars->start), philo->index + 1);
	else if (cod == 1)
		printf("%llu %d is sleeping\n",
			ft_gt(philo->vars->start), philo->index + 1);
	else if (cod == 2)
		printf("%llu %d is eating\n",
			ft_gt(philo->vars->start), philo->index + 1);
	else if (cod == 3)
		printf("%llu %d died\n",
			ft_gt(philo->vars->start), philo->index + 1);
	else if (cod == 4)
		printf("%llu %d has taken a fork\n",
			ft_gt(philo->vars->start), philo->index + 1);
	if (cod != 3)
		pthread_mutex_unlock(&(philo->vars->write_mutex));
}
