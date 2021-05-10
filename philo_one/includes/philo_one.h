/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:36:42 by afoulqui          #+#    #+#             */
/*   Updated: 2021/05/07 16:02:05 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE
# define PHILO_ONE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef int bool;
# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	int		nbr_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		nbr_must_eat;
}				t_data;

/*
**	MAIN
*/

int			check_args(int argc, char **argv, t_data *data);
int			print_return(char *err_msg);

/*
**	UTILS
*/

int			ft_isdigit(int c);
bool		ft_onlydigit(char **str);
int			ft_atoi(const char *str);


#endif