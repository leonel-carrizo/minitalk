/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:58:38 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:24:23 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void		*d;

	if ((!dest && !src) || (dest == src))
		return (dest);
	d = dest;
	if (dest > src)
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	else
		while (n--)
			*(char *)dest++ = *(char *)src++;
	return (d);
}
