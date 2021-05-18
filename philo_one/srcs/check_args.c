/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:16:45 by afoulqui          #+#    #+#             */
/*   Updated: 2021/05/10 10:17:25 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	print_return(char *err_msg)
{
	printf("ERROR : %s.\n", err_msg);
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
	if (argc == 6)
		data->nbr_must_eat = ft_atoi(argv[5]);
	return (1);
}