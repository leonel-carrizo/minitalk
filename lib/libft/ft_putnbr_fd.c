/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:25:57 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:26:19 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;
	char		c[10];
	int			i;

	if (n > INT_MAX || n < INT_MIN)
		return ;
	nb = n;
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	i = 0;
	while (nb)
	{
		c[i++] = nb % 10 + '0';
		nb /= 10;
	}
	while (i > 0)
		write (fd, &c[--i], 1);
}
