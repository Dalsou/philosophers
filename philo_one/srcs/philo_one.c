/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:46:29 by afoulqui          #+#    #+#             */
/*   Updated: 2021/05/10 10:17:40 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			main(int argc, char **argv)
{
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	if (check_args(argc, argv, &data) < 0)
		return (-1);
}