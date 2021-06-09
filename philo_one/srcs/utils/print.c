/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:29:07 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/07 17:57:05 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putchar(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
	if (nb <= 9)
		ft_putchar((nb % 10) + 48);
}

void	ft_putstr(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}