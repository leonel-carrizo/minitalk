/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:05:04 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/19 12:47:03 by lcarrizo         ###    ###london.com    */
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
void			char_to_bin(char c, int nbr[]);
unsigned int	get_bit(char c);

#endif
