/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:35:42 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:30:35 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

static size_t	str_len(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

static char	*new_str(int len)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	str = new_str(str_len(s));
	if (!str)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(str + i) = f(i, s[i]);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
