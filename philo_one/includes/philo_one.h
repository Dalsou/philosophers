/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:36:42 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/09 09:41:18 by afoulqui         ###   ########.fr       */
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

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DEAD 5
# define END 6

typedef struct s_phi
{
	int					id;
	int					nb_meals;
	long long	 		start_time;
	pthread_mutex_t		*r_frk;
	pthread_mutex_t		*l_frk;
	pthread_t			main_thread;
	pthread_t			status_thread;	
	struct s_data		*data;
}						t_phi;

typedef struct s_data
{
	int					nbr_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					nbr_must_eat;
	int					done;
	long long 			init_time;
	t_phi				*phi;
	pthread_mutex_t		*msg;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*status;
}						t_data;

/*
**	MAIN
*/

int			check_args(int argc, char **argv, t_data *data);
void		*init_thread(t_data *data);
void		*routine(void *args);
void		display(t_phi *phi, int state);
void		clean_all(t_data *data);
void		*check_status(void *args);


/*
**	UTILS
*/

int			ft_isdigit(int c);
bool		ft_onlydigit(char **str);
int			ft_atoi(const char *str);
int			ft_strlen(char *str);
void		ft_putchar(char c);
void		ft_putnbr(long n);
void		ft_putstr(char *str);
long long	get_time(void);
void		my_usleep(long long time);

#endif