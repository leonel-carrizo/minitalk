/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:26:41 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/08 14:43:51 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putcharf(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstrf(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_putstrf("(null)"));
	while (*s)
		len += (write(1, s++, 1));
	return (len);
}

int	ft_putnumber(long nbr)
{
	char		c[10];
	int			i;
	int			count;
	long long	n;

	n = nbr;
	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	while (n)
	{
		c[i++] = n % 10 + '0';
		n /= 10;
	}
	while (i > 0)
		count += write(1, &c[--i], 1);
	return (count);
}

int	ft_printaddr(void *ptr, char format)
{
	unsigned long long	n;
	int					len;

	if (ptr == NULL)
		return (ft_putstrf("(nil)"));
	len = 0;
	len += ft_putstrf("0x");
	if (ptr == 0)
		len += ft_putcharf('0');
	n = (unsigned long long)ptr;
	len += ft_printhexa(n, format);
	return (len);
}

int	ft_printhexa(unsigned long nbr, char format)
{
	int			n;
	int			rem;
	int			i;
	const char	*base;
	char		hex[16];

	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	n = 0;
	if ((unsigned long int)nbr <= 9)
		return (ft_putcharf(nbr + '0'));
	while ((unsigned long int)nbr)
	{
		rem = nbr % 16;
		hex[i++] = base[rem];
		nbr /= 16;
	}
	while (i > 0)
		n += write(1, &hex[--i], 1);
	return (n);
}
