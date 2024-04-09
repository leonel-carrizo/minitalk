/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:06:38 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:22:50 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

//int	main(void)
//{
//	char	x[] = "Hola mundo";
//	char	y[] = "Hola Mundo";
//
//	printf("This is FT: %d\n", ft_memcmp(x, y, 10));
//	printf("This is C: %d\n", memcmp(x, y, 10));
//	return (0);
//}

//DESCRIPTION
//The memcmp() function compares the first n bytes (each interpreted as 
//unsigned char) of the memory areas s1 and s2.
//
//RETURN VALUE
//The  memcmp() function returns an integer less than, equal to, or greater
//than zero if the first n bytes of s1 is found, respectively, to  be  less
//than, to match, or be greater than the first n bytes of s2.
//
//For  a  nonzero  return  value, the sign is determined by the sign of the
//difference between the first pair of bytes (interpreted as unsigned char)
//that differ in s1 and s2.
//
//If n is zero, the return value is zero.
