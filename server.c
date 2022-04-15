/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:37:22 by wboutzou          #+#    #+#             */
/*   Updated: 2022/04/15 03:46:52 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int pow)
{
	int	i;
	int	n;

	i = 1;
	n = 1;
	while (i <= pow)
	{
		n *= 2;
		i++;
	}
	return (n);
}

void	sig_handler(int signum)
{
	static int	i = 7;
	static int	n = 0;

	if (signum == SIGUSR1)
		n += 1 * ft_pow(i);
	i--;
	if (i == -1)
	{
		write(1, &n, 1);
		i = 7;
		n = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR2, sig_handler);
	signal(SIGUSR1, sig_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
