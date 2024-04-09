/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:18:26 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:26:33 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

void	ft_putnbr(int n)
{
	long long	nb;
	char		c[10];
	int			i;

	if (n > INT_MAX || n < INT_MIN)
		return ;
	nb = n;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	i = 0;
	while (nb)
	{
		c[i++] = nb % 10 + '0';
		nb /= 10;
	}
	while (i > 0)
		write (1, &c[--i], 1);
}
