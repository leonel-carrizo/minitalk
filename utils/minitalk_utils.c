/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:16:26 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/18 15:29:13 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/* Add the char c to the str, it does not set NULL termination.
 * the callback fucntion must free the last memory allaction */
void	add_char(char c, char **str, int n)
{
	int		j;
	int		i;
	char	*temp;
	char	*ptr;

	temp = (char *)malloc(sizeof(char) * (n + 1));
	if (!temp)
	{
		free(*str);
		return ;
	}
	if (!*str && n == 0)
	{
		temp[n] = c;
		*str = temp;
		return ;
	}
	ptr = *str;
	i = n + 1;
	j = -1;
	while (--i > 0 && ++j >= 0)
		temp[j] = ptr[j];
	temp[n] = c;
	free(*str);
	*str = temp;
}

/* fucntion write a message in the standar error 
 * free the momory storaged in the str given*/
void	error(char *mess, char *str)
{
	ft_putstr_fd(mess, 2);
	if (str)
	{
		free(str);
		str = NULL;
	}
	exit(EXIT_FAILURE);
}

/* Get each bit from the char given, it must be called recursively.
 * maintains the position of the bit until the end of the program */
unsigned int	get_bit(char c)
{
	static int		i = 0;
	unsigned int	bit;

	bit = ((c >> i) & 1);
	i++;
	return (bit);
}
