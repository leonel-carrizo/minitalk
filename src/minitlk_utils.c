/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitlk_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:16:26 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/16 22:25:39 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/* fucntion write a message in the standar error 
 * free the momory storaged in the str given*/
void	error(const char *mess, char *str)
{
	ft_putstr_fd(mess, 2);
	if (str)
		free(str);
	exit(EXIT_FAILURE);
}
