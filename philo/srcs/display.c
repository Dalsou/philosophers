/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:16:06 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 10:29:34 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*find_msg(int state)
{
	if (state == FORK)
		return (" : has taken a fork\n");
	if (state == EAT)
		return (" : is eating\n");
	if (state == SLEEP)
		return (" : is sleeping\n");
	if (state == THINK)
		return (" : is thinking\n");
	if (state == DEAD)
		return (" : has died\n");
	return (NULL);
}

void	display(t_phi *phi, int state)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (state == END)
		printf("All philosophers have eaten %d time(s)\n", g_data[LIMIT_MEAL]);
	else
		printf("%d \tPhilosopher_%d %s", chrono(&g_saved_time,
				&now), phi->id + 1, find_msg(state));
}
