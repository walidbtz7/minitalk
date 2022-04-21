/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:37:22 by wboutzou          #+#    #+#             */
/*   Updated: 2022/04/21 13:07:22 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	sig_handler(int signum)
{
	static int	i = 7;
	static int	n = 0;

	if (signum == SIGUSR1)
		n |= 1;
	else if (signum == SIGUSR2)
		n |= 0;
	i--;
	if (i == -1)
	{
		write(1, &n, 1);
		i = 7;
		n = 0;
	}
	else
		n =  n << 1;
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR2, sig_handler);
	signal(SIGUSR1, sig_handler);
	while (1)
		pause();
	return (0);
}
