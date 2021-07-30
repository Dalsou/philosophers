/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:16:06 by afoulqui          #+#    #+#             */
/*   Updated: 2021/07/29 11:58:29 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*find_msg(int state)
{
	if (state == FORK)
		return (" has taken a fork\n");
	if (state == EAT)
		return (" is eating\n");
	if (state == SLEEP)
		return (" is sleeping\n");
	if (state == THINK)
		return (" is thinking\n");
	if (state == DEAD)
		return (" has died\n");
	return (NULL);
}

void	display(t_philo *philo, int status)
{
	long int	now;

	now = 0;
	if (status == END)
	{
		write(1, "All philosophers have eaten ", 29);
		ft_putnbr(philo->table->data[LIMIT_MEAL]);
		write(1, " time(s)\n", 10);
	}
	else
	{
		now = get_time();
		ft_putnbr((int)(now - philo->table->saved_time));
		write(1, "\tPhilosopher_", 14);
		ft_putnbr(philo->id);
		write(1, find_msg(status), ft_strlen(find_msg(status)));
	}
}
