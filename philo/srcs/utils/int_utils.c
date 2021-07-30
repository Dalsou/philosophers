/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:26:35 by afoulqui          #+#    #+#             */
/*   Updated: 2021/07/13 14:55:53 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_bool	ft_onlydigit(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	res;

	neg = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\f' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v'))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}

void	ft_putnbr(int n)
{
	long lnbr;
	char c;

	lnbr = n;
	if (lnbr >= -2147483648 && lnbr <= 2147483648)
	{
		if (lnbr > 9)
		{
			ft_putnbr(lnbr / 10	);
			c = lnbr % 10 + '0';
			write(1, &c, 1);
		}
		else
		{
			c = lnbr + '0';
			write(1, &c, 1);
		}
	}
}

