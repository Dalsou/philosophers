/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:16:06 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/02 18:44:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*find_msg(int status)
{
	if (status == FORK)
		return (" has taken a fork\n");
	if (status == EAT)
		return (" is eating\n");
	if (status == SLEEP)
		return (" is sleeping\n");
	if (status == THINK)
		return (" is thinking\n");
	if (status == DEAD)
		return (" HAS DIED\n");
	return (NULL);
}

void	display(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->table->msg);
	if (philo->table->stop == FALSE)
	{
		if (status == END)
		{
			write(1, "All philosophers have eaten ", 29);
			ft_putnbr(philo->table->data[LIMIT_MEAL]);
			write(1, " time(s)\n", 10);
			philo->table->stop = TRUE;
			return ;
		}
		else
		{
			ft_putnbr(get_time() - philo->table->saved_time);
			write(1, "\tPhilosopher_", 14);
			ft_putnbr(philo->id);
			write(1, find_msg(status), ft_strlen(find_msg(status)));
			if (status == DEAD)
			{
				philo->table->stop = TRUE;
				return ;
			}	
		}
		pthread_mutex_unlock(&philo->table->msg);
	}
}
