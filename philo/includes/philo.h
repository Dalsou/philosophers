/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:43:26 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/11 16:12:50 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef int bool;
# define TRUE 1
# define FALSE 0

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DEAD 5
# define END 6

# define N_PHI 0
# define T_DIE 1
# define T_EAT 2
# define T_SLEEP 3
# define LIMIT_MEAL 4

int				g_data[5];
int				g_meals;
struct timeval	g_saved_time;
pthread_mutex_t *g_forks;
pthread_mutex_t g_msg;
pthread_mutex_t g_checker;
pthread_mutex_t	g_watchdog;

typedef struct s_phi
{
	int					id;
	int					nb_meals;
	struct timeval	 	start_time;
	pthread_mutex_t		*r_frk;
	pthread_mutex_t		*l_frk;
	pthread_t			main_thread;
	pthread_t			checker_thread;	
}						t_phi;

/*
**	MAIN
*/

int				parse(int argc, char **argv, t_phi **phi);
void			*routine(void *ptr);
void			*check_status(void *ptr);
void			display(t_phi *phi, int state);

/*
**	UTILS
*/

int				ft_isdigit(int c);
bool			ft_onlydigit(char **str);
int				ft_atoi(const char *str);
void 			clear_all(t_phi *phi);
int				chrono(struct timeval *a, struct timeval *b);

#endif