/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:35:28 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/09 09:41:53 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		check_meals(t_phi *phi)
{
	pthread_mutex_lock(phi->data->status);
	if (phi->nb_meals == phi->data->nbr_must_eat)
	{
		phi->data->done++;
		phi->nb_meals++;
	}
	pthread_mutex_unlock(phi->data->status);
}

void			*check_status(void *args)
{
	t_phi	*phi;

	phi = args;
	while (1)
	{
		check_meals(phi);
		if (phi->data->done == phi->data->nbr_must_eat)
		{
			pthread_mutex_lock(phi->data->msg);
			display(phi, END);
			return (NULL);
		}
		if ((get_time() - phi->start_time) > phi->data->t_die)
		{
			pthread_mutex_lock(phi->data->msg);
			display(phi, DEAD);
			return (NULL);
		}
	}
}