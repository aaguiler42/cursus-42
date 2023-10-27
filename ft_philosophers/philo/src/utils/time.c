/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:52:02 by aaguiler          #+#    #+#             */
/*   Updated: 2022/07/14 14:55:53 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	ft_gt(uint64_t init)
{
	struct timeval		ti;
	long long unsigned	tmp;

	gettimeofday(&ti, NULL);
	tmp = ti.tv_sec * 1000 + ti.tv_usec / 1000 - init;
	return (tmp);
}

void	ft_sleep(uint64_t time_2_sleep)
{
	uint64_t	start;

	start = ft_gt(0);
	while ((ft_gt(0) - start) < time_2_sleep)
		usleep(235);
}
