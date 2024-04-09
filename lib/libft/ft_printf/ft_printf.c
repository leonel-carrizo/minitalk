/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:19:57 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/08 14:29:05 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* check which specifiers and handles in according to each case  */
static int	ft_check_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putcharf(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstrf(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnumber((long)va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnumber((long)va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_printhexa(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_printaddr(va_arg(args, void *), format));
	else if (format == '%')
		return (ft_putcharf('%'));
	else
		return (-1);
}

/* Produce output according to a format and write output to stdout, */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		nprint;

	nprint = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			nprint += ft_check_format(*format, args);
		}
		else
			nprint += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (nprint);
}
