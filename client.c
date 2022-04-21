/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:20:55 by wboutzou          #+#    #+#             */
/*   Updated: 2022/04/21 13:10:27 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i] != '\0')
		{
			j = 7;
			while (j >= 0)
			{
				if (argv[2][i] & 1 << j)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				j--;
				usleep(50); 
			}
			i++;
		}
	}
	return (0);
}
