/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:01:39 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:19:38 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated_memory;

	if ((nmemb >= 42949672926 || size >= 42949672926) && nmemb && size)
		return (NULL);
	allocated_memory = (void *)malloc(nmemb * size);
	if (allocated_memory == NULL)
		return (NULL);
	ft_bzero(allocated_memory, nmemb * size);
	return (allocated_memory);
}
