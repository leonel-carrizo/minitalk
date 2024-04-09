/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:34 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:32:08 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

static size_t	chrcmp(const char *set, const char c)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && chrcmp(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && chrcmp(set, s1[end - 1]))
		end--;
	ptr = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		ptr[i] = s1[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
