/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:20:10 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 10:35:45 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_phi	*init_phi(void)
{
	t_phi	*phi;
	int		i;

	phi = malloc(sizeof(t_phi) * g_data[N_PHI]);
	if (!phi)
		return (NULL);
	i = 0;
	while (i < g_data[N_PHI])
	{
		phi[i].id = i;
		phi[i].nb_meals = 0;
		phi[i].l_frk = &g_forks[i];
		phi[i].r_frk = &g_forks[(i + 1) % g_data[N_PHI]];
		phi[i].main_thread = malloc(sizeof(pthread_t));
		phi[i].checker_thread = malloc(sizeof(pthread_t));
		i++;
	}
	return (phi);
}

int	init_mutex(void)
{
	int		i;

	g_forks = malloc(sizeof(pthread_mutex_t) * g_data[N_PHI]);
	if (!g_forks)
		return (1);
	i = 0;
	while (i < g_data[N_PHI])
	{
		pthread_mutex_init(&g_forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&g_msg, NULL);
	pthread_mutex_init(&g_checker, NULL);
	pthread_mutex_init(&g_watchdog, NULL);
	return (0);
}

static int	print_return(char *err_msg)
{
	printf("ERROR : %s.\n", err_msg);
	return (1);
}

int	parse(int argc, char **argv, t_phi **phi)
{
	if (argc < 5 || argc > 6)
		return (print_return("wrong number of arguments"));
	if (ft_onlydigit(argv) == FALSE)
		return (print_return("only numbers are accepted as arguments"));
	g_data[N_PHI] = ft_atoi(argv[1]);
	if (g_data[N_PHI] < 2)
		return (print_return("not enough philosophers"));
	g_data[T_DIE] = ft_atoi(argv[2]);
	g_data[T_EAT] = ft_atoi(argv[3]);
	g_data[T_SLEEP] = ft_atoi(argv[4]);
	if (argc == 6 && argv[5] > 0)
		g_data[LIMIT_MEAL] = ft_atoi(argv[5]);
	else
		g_data[LIMIT_MEAL] = -1;
	if (init_mutex())
		return (1);
	*phi = init_phi();
	if (*phi == NULL)
		return (1);
	g_meals = 0;
	return (0);
}
