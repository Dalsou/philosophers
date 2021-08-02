/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:09:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/02 18:54:02 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*philo;
	t_table	table;

	if (parse(argc, argv, &philo, &table))
	{
		clear_all(&philo, &table);
		return (-1);
	}
	table.saved_time = get_time();
	i = 0;
	while (i < table.data[N_PHI])
	{
		if (pthread_create(&philo[i].main_thread, NULL, &routine, (void *)&philo[i]))
			return (-1);
		i++;
	}
	i = 0;
	while (i < table.data[N_PHI])
	{
		printf("hello inside\n");
		pthread_join(philo[i].main_thread, NULL);
		i++;
	}
	printf("hello after\n");
	clear_all(&philo, &table);
	return (0);
}
