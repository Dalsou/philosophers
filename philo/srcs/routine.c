/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:30:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/02 18:55:27 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping_thinking(t_philo *philo)
{
	display(philo, SLEEP);
	ft_sleep(philo->table->data[T_SLEEP]);
	display(philo, THINK);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_frk);
	display(philo, FORK);
	if (!philo->r_frk)
	{
		ft_sleep(philo->table->data[T_EAT] * 2);
		return ;
	}
	pthread_mutex_lock(philo->r_frk);
	philo->nb_meals++;
	display(philo, FORK);
	display(philo, EAT);
	philo->start_time = get_time();
	ft_sleep(philo->table->data[T_EAT]);
	pthread_mutex_unlock(philo->r_frk);
	pthread_mutex_unlock(philo->l_frk);
}

void	*check_liveness(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	ft_sleep(philo->table->data[T_DIE] + 1);
	pthread_mutex_lock(&philo->table->checker);
	if (philo->table->stop == FALSE
		&& (get_time() - philo->start_time >= (long)philo->table->data[T_DIE]))
		display(philo, DEAD);
	pthread_mutex_unlock(&philo->table->checker);
	return (NULL);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_sleep(philo->table->data[T_EAT] / 10);
	while (philo->table->stop == FALSE)
	{
		if (pthread_create(&philo->checker_thread, NULL, &check_liveness, philo))
			return (NULL);
		eating(philo);
		if (philo->nb_meals == philo->table->data[LIMIT_MEAL])
		{
			pthread_mutex_lock(&philo->table->checker);
			philo->table->meals++;
			philo->nb_meals++;
			if (philo->table->meals == philo->table->data[LIMIT_MEAL])
				display(philo, END);
			pthread_mutex_unlock(&philo->table->checker);
		}
		if (philo->table->stop == FALSE)
			sleeping_thinking(philo);
		pthread_detach(philo->checker_thread);
	}
	return (NULL);
}