/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:38:14 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/07 17:59:41 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static char		*find_msg(int state)
{
	if (state == FORK)
		return (" : has taken a fork.\n");
	if (state == EAT)
		return (" : is eating.\n");
	if (state == SLEEP)
		return (" : is sleeping.\n");
	if (state == THINK)
		return (" : is thinking.\n");
	if (state == DEAD)
		return (" : has died.\n");
	return ("finish.\n");
}

void			display(t_phi *phi, int state)
{
	long long		time;

	if (state == END)
	{
		ft_putstr("All philosophers have eaten ");
		ft_putnbr(phi->data->nbr_must_eat);
		ft_putstr(" time(s).\n");
	}
	else
	{
		time = get_time() - phi->data->init_time;
		ft_putnbr((long)time);
		ft_putstr("\tPhilosoper_");
		ft_putnbr(phi->id);
		ft_putstr(find_msg(state));
	}
}