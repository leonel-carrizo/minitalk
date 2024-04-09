/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:49:56 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:28:34 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	ptr = (char *)malloc(len + 1);
	new_str = ptr;
	if (ptr != NULL)
	{
		while (len--)
			*ptr++ = *s++;
		*ptr = '\0';
	}
	return (new_str);
}
