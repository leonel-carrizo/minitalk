/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:05:04 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/18 15:55:53 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../lib/libft/include/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void			error(char *mess, char *str);
void			add_char(char c, char **str, int n);
unsigned int	get_bit(char c);

#endif
