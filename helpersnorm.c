/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpersnorm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:47:38 by wboutzou          #+#    #+#             */
/*   Updated: 2022/04/14 20:50:21 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check(char c, va_list args)
{	
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (c == 'X')
		count += fthexa(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	if (c == 'x')
		count += fthexa(va_arg(args, unsigned int), "0123456789abcdef", 16);
	if (c == 'u')
		count += fthexa(va_arg(args, unsigned int), "0123456789", 10);
	if (c == 'p')
	{
		ft_putstr("0x");
		count += 2;
		count += ft_phexa(va_arg(args, unsigned long long));
	}
	if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{	
		if (*s == '%')
		{
			s++;
			count += ft_check((char)*s, args);
		}
		else
		{
			ft_putchar(*s);
			count++;
		}
		s++;
	}
	va_end(args);
	return (count);
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
