/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:22:43 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 10:25:47 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	chrono(struct timeval *a, struct timeval *b)
{
	int	sec;
	int	u_sec;

	sec = (b->tv_sec - a->tv_sec) * 1000;
	u_sec = (b->tv_usec - a->tv_usec) / 1000;
	return (sec + u_sec);
}

void 	clear_all(t_phi *phi)
{
	int	i;

	i = 0;
	while (i < g_data[N_PHI])
	{
		pthread_mutex_destroy(&g_forks[i]);
		i++;
	}
	free(g_forks);
	pthread_mutex_destroy(&g_msg);
	pthread_mutex_destroy(&g_checker);
	pthread_mutex_destroy(&g_watchdog);
	free(phi);
}
