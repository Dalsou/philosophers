/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:30:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/07/29 18:58:00 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg);
	display(philo, SLEEP);
	pthread_mutex_unlock(& philo->table->msg);
	ft_sleep(philo->table->data[T_SLEEP]);
	pthread_mutex_lock(&philo->table->msg);
	display(philo, THINK);
	pthread_mutex_unlock(& philo->table->msg);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_frk);
	pthread_mutex_lock(&philo->table->msg);
	display(philo, FORK);
	pthread_mutex_unlock(&philo->table->msg);
	if (!philo->r_frk)
	{
		ft_sleep(philo->table->data[T_DIE]);
		return ;
	}
	pthread_mutex_lock(philo->r_frk);
	pthread_mutex_lock(&philo->table->msg);
	display(philo, FORK);
	pthread_mutex_unlock(&philo->table->msg);
	pthread_mutex_lock(&philo->table->msg);
	display(philo, EAT);
	pthread_mutex_unlock(&philo->table->msg);
	philo->start_time = get_time();
	philo->nb_meals++;
	ft_sleep(philo->table->data[T_EAT]);
	pthread_mutex_unlock(philo->l_frk);
	pthread_mutex_unlock(philo->r_frk);
	sleeping_thinking(philo);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_create(&philo->checker_thread, NULL, check_status, (void *)philo);
	if (philo->id % 2 == 0)
		ft_sleep(philo->table->data[T_EAT] / 10);
	while (1)
	{
		eating(philo);
	}
}
