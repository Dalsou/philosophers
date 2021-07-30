/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:09:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/07/29 16:21:58 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*philo;
	t_table	table;

	if (parse(argc, argv, &philo, &table))
		return (-1);
	table.saved_time = get_time();
	pthread_mutex_lock(&table.watchdog);
	i = 0;
	while (i < table.data[N_PHI])
	{
		pthread_create(&philo[i].main_thread, NULL, routine, (void *)&philo[i]);
		i++;
	}
	pthread_mutex_lock(&table.watchdog);
	clear_all(&philo, &table);
	return (0);
}
