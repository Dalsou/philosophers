/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:46:29 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/09 09:41:39 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void			init_mutex(t_data *data)
{
	data->msg = malloc(sizeof(pthread_mutex_t));
	data->status = malloc(sizeof(pthread_mutex_t));
	if (!data->msg || !data->status)
		return ;
	pthread_mutex_init(data->msg, NULL);
	pthread_mutex_init(data->status, NULL);
}

void			*init_thread(t_data *data)
{
	int			i;

	init_mutex(data);
	data->init_time = get_time();
	i = 0;
	while (i < data->nbr_philo)
	{
		data->phi[i].start_time = get_time();
		if (pthread_create(&data->phi[i].main_thread, NULL, 
							routine, (void*)&data->phi[i]))
			return (NULL);
		i++;
	}
	clean_all(data);
	return (NULL);
}

int			main(int argc, char **argv)
{
	t_data		*data;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	if (check_args(argc, argv, data) < 0)
		return (-1);
	init_thread(data);
	return (0);
}