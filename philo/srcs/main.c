/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:09:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/02 11:07:29 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop(t_philo **philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->data[N_PHI])
		pthread_join(philo[i]->main_thread, NULL);
	pthread_mutex_destroy(&table->msg);
	i = 0;
	while (i < table->data[N_PHI])
		pthread_mutex_destroy(&table->forks[i]);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_table	table;
	int		i;

	if (parse(argc, argv, &philo, &table))
		return (-1);
	table.saved_time = get_time();
	i = 0;
	while (i < table.data[N_PHI])
	{
		if (pthread_create(&philo[i].main_thread, NULL, routine, &philo[i]))
		{
			clear_all(&philo, &table);
			return (1);		
		}
		i++;
	}
	stop(&philo, &table);
	clear_all(&philo, &table);
	return (0);
}
