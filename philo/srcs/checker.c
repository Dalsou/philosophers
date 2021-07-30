/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:31:55 by afoulqui          #+#    #+#             */
/*   Updated: 2021/07/29 17:31:30 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->checker);
	if (philo->nb_meals == philo->table->data[LIMIT_MEAL])
	{
		philo->table->meals++;
		philo->nb_meals++;
	}
	pthread_mutex_unlock(&philo->table->checker);
	if (philo->table->meals == philo->table->data[N_PHI])
	{
		pthread_mutex_lock(&philo->table->msg);
		display(philo, END);
		pthread_mutex_unlock(&philo->table->watchdog);
	}
}

void	check_liveness(t_philo *philo)
{
	int		now;
	int		time;

	now = get_time();
	time = now - philo->start_time;
	if (time > philo->table->data[T_DIE])
	{
		pthread_mutex_lock(&philo->table->msg);
		display(philo, DEAD);
		pthread_mutex_unlock(&philo->table->watchdog);
	}
}

void	*check_status(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	ft_sleep(philo->table->data[T_DIE] + 1);
	while (1)
	{
		if (philo->table->data[LIMIT_MEAL] != -1)
			check_meals(philo);
		check_liveness(philo);
	}
	return (NULL);
}
