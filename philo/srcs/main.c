/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:09:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 10:29:55 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_phi	*phi;

	phi = NULL;
	if (parse(argc, argv, &phi))
		return (-1);
	gettimeofday(&g_saved_time, NULL);
	pthread_mutex_lock(&g_watchdog);
	i = 0;
	while (i < g_data[N_PHI])
	{
		pthread_create(&phi[i].main_thread, NULL, routine, (void *)&phi[i]);
		i++;
	}
	pthread_mutex_lock(&g_watchdog);
	clear_all(phi);
	return (0);
}
