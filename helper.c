/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:47:48 by wboutzou          #+#    #+#             */
/*   Updated: 2022/04/15 03:45:39 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int a)
{
	int		i;
	long	nb;

	i = 0;
	nb = (long)a;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
	{
		i += ft_putchar(nb + '0');
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	e;
	int				i;
	int				signe;

	e = 0;
	signe = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			signe = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		e = (e * 10) + (nptr[i] - 48);
		i++;
	}
	return (e * signe);
}
