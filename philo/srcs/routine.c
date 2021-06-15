/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:30:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 10:36:52 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thinking(t_phi *phi)
{
	pthread_mutex_lock(&g_msg);
	display(phi, THINK);
	pthread_mutex_unlock(&g_msg);
	return (NULL);
}

void	*sleeping(t_phi *phi)
{
	pthread_mutex_lock(&g_msg);
	display(phi, SLEEP);
	pthread_mutex_unlock(&g_msg);
	usleep(g_data[T_SLEEP] * 1000);
	return (NULL);
}	

void	*eating(t_phi *phi)
{
	pthread_mutex_lock(phi->l_frk);
	pthread_mutex_lock(phi->r_frk);
	pthread_mutex_lock(&g_msg);
	phi->nb_meals++;
	gettimeofday(&phi->start_time, NULL);
	display(phi, FORK);
	display(phi, FORK);
	display(phi, EAT);
	pthread_mutex_unlock(&g_msg);
	usleep(g_data[T_EAT] * 1000);
	pthread_mutex_unlock(phi->l_frk);
	pthread_mutex_unlock(phi->r_frk);
	return (NULL);
}

void	*routine(void *ptr)
{
	t_phi	*phi;

	phi = ptr;
	pthread_create(&phi->checker_thread, NULL, check_status, (void *)phi);
	while (1)
	{
		eating(phi);
		sleeping(phi);
		thinking(phi);
	}
}
