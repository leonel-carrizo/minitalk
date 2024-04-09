/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:58:24 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:31:49 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*found;

	found = NULL;
	while (*s)
	{
		if (*s == (char)c)
			found = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)found);
}
