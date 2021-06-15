/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:31:55 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 10:28:40 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_meals(t_phi *phi)
{
	pthread_mutex_lock(&g_checker);
	if (phi->nb_meals == g_data[LIMIT_MEAL])
	{
		g_meals++;
		phi->nb_meals++;
	}
	pthread_mutex_unlock(&g_checker);
	if (g_meals == g_data[N_PHI])
	{
		pthread_mutex_lock(&g_msg);
		display(phi, END);
		pthread_mutex_unlock(&g_watchdog);
	}
}

void	check_liveness(t_phi *phi)
{
	struct timeval	now;
	int				ms;

	gettimeofday(&now, NULL);
	ms = chrono(&phi->start_time, &now);
	if (ms >= g_data[T_DIE])
	{
		pthread_mutex_lock(&g_msg);
		display(phi, DEAD);
		pthread_mutex_unlock(&g_watchdog);
	}
}

void	*check_status(void *ptr)
{
	t_phi			*phi;

	phi = (t_phi *)ptr;
	while (1)
	{
		check_meals(phi);
		check_liveness(phi);
	}
	return (NULL);
}
