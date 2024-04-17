/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:16:26 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/17 06:10:31 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
	static int	i = 0;
	unsigned int	bit;

	bit = ((c >> i) & 1);
	i++;
	return (bit);
}
