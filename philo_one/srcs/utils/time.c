/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:31:05 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/07 16:01:09 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long long	get_time(void)
{
	struct timeval	tmp_time;
	long long		time;

	gettimeofday(&tmp_time, NULL);
	time = tmp_time.tv_sec * 1000 + tmp_time.tv_usec / 1000;
	return (time);
}

void	my_usleep(long long time)
{
	long long 		stop;

	stop = get_time() + time;
	while (get_time() < stop)
		usleep (1);
}
