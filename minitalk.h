/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:49:16 by wboutzou          #+#    #+#             */
/*   Updated: 2022/04/14 20:49:46 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <signal.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_strlen(const char *str);
int	ft_putnbr(int a);
int	ft_check(char c, va_list args);
int	fthexa(unsigned int nb, char *base, int b);
int	ft_phexa(unsigned long long nb);
int	ft_atoi(const char *nptr);

#endif