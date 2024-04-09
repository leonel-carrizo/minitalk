/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:11:09 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:31:22 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t len)
{
	size_t	i;

	if (!str && !len)
		return (NULL);
	if (!*to_find)
		return ((char *)str);
	while (*str && len--)
	{
		i = 0;
		while (str[i] == to_find[i] && to_find[i] && i <= len)
		{
			if (!to_find[i + 1])
				return ((char *)str);
			i++;
		}
		str++;
	}
	return (NULL);
}
