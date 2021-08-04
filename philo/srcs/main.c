/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:09:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/04 14:16:05 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_thread(t_table *table)
{
	int			i;
	pthread_t	thread;

	table->saved_time = get_time();
	i = 0;
	while (i < table->data[N_PHI])
	{
		if (pthread_create(&thread, NULL, routine, (void *)&table->philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < table->data[N_PHI])
	{
		pthread_join(thread, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table		table;
	int			ret;

	ret = 0;
	if (parse(argc, argv, &table))
		ret = -1;
	if (init_thread(&table))
		ret = -1;
	clear_all(&table);
	return (ret);
}
