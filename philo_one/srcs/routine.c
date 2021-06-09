/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:22:21 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/07 16:15:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void 		*thinking(t_phi *phi)
{
	pthread_mutex_lock(phi->data->msg);
	display(phi, THINK);
	pthread_mutex_unlock(phi->data->msg);
	return (NULL);
}

void 		*sleeping(t_phi *phi)
{
	pthread_mutex_lock(phi->data->msg);
	display(phi, SLEEP);
	pthread_mutex_unlock(phi->data->msg);
	my_usleep(phi->data->t_sleep);
	return (NULL);
}	

void		*eating(t_phi *phi)
{
	if (phi->data->nbr_must_eat != 0)
	{
		if (phi->id % 2)
		{
			pthread_mutex_lock(phi->r_frk);
			pthread_mutex_lock(phi->l_frk);
		}
		else
		{
			pthread_mutex_lock(phi->l_frk);
			pthread_mutex_lock(phi->r_frk);
		}
		pthread_mutex_lock(phi->data->msg);
		phi->data->nbr_must_eat--;
		phi->start_time = get_time();
		display(phi, FORK);
		display(phi, FORK);
		display(phi, EAT);
		pthread_mutex_unlock(phi->data->msg);
		my_usleep(phi->data->t_eat);
		pthread_mutex_unlock(phi->l_frk);
		pthread_mutex_unlock(phi->r_frk);
	}
	return (NULL);
}

void		*routine(void *args)
{
	t_phi		*phi;

	phi = args;
	pthread_create(&phi->status_thread, NULL, check_status, phi);
	while (1)
	{
		eating(phi);
		sleeping(phi);
		thinking(phi);
	}
	return (NULL);
}