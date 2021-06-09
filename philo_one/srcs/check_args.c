/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:16:45 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/07 16:46:43 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	init_phi(t_data *data)
{
	int		i;

	data->phi = malloc(sizeof(t_data) * data->nbr_philo);
	if (!data->phi)
		return (-1);
	i = 0;
	while (i < data->nbr_philo)
	{
		data->phi[i].id = i;
		data->phi[i].r_frk = &data->forks[(i + 1) % data->nbr_philo];
		data->phi[i].l_frk = &data->forks[i];
		pthread_mutex_init(&data->forks[i], NULL);
		data->phi[i].data = data;
		i++;
	}
	return (0);
}

static int	print_return(char *err_msg)
{
	ft_putstr("ERROR : ");
	ft_putstr(err_msg);
	ft_putstr(".\n");
	return (-1);
} 

int			check_args(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		return (print_return("wrong number of arguments"));
	if (ft_onlydigit(argv) == FALSE)
		return (print_return("only numbers are accepted as arguments"));
	if ((data->nbr_philo = ft_atoi(argv[1])) < 2)
		return (print_return("not enough philosophers"));
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6 && argv[5] > 0)
		data->nbr_must_eat = ft_atoi(argv[5]);
	else 
		data->nbr_must_eat = -1;
	if (!(data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo)))
		return (-1);
	if (init_phi(data) < 0)
		return (-1);
	return (0);
}