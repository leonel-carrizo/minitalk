/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:05:04 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/16 22:42:08 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft/include/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	handler_signal(int signum, siginfo_t *info, void *ucontext);
void	error(const char *mess, char *str);

#endif
