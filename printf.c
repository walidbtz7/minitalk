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