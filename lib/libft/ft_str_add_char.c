/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:24:53 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/09 18:30:24 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

/* Return the char given */
static char	*ft_straddc_first(char c)
{
	char	*add;

	add = (char *)malloc(sizeof(char) * 2);
	if (!add)
		return (NULL);
	add[0] = c;
	add[1] = '\0';
	return (add);
}

/* Add a char in the str given, if there is not str, return the char
 * the programer should free the memory after using the function
 */
char	*ft_str_add_char(char *str, char c)
{
	char	*add;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_straddc_first(c));
	add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!add)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		add[i] = str[i];
	free(str);
	add[i++] = c;
	add[i] = '\0';
	return (add);
}
