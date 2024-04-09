/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:54:37 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/09 20:57:29 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/**/
char	*print_message(char *str)
{
	ft_putstr_fd(str, 1);
	free(str);
	return (NULL);
}

/* Handle the signal recived and acts depending on which one is received */
void	handler_signal(int signum, siginfo_t *info, void *ucontext)
{
	static int				i;
	static unsigned char	bit;
	static unsigned char	c;
	static char	*message = 0;

	(void)ucontext;
	(void)info;
	if (signum == SIGUSR2)
	{
		bit = 1 << i;
		c += bit;
	}
	else if (signum == SIGUSR1)
	{
		bit = 0 << i;
		c += bit;
	}
	i++;
	if (i == 8)
	{
		if (c)
			message = ft_str_add_char(message, c);
		else 
			message = print_message(message);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;
	sigset_t			sa_mask;

	act.sa_handler = 0;
	sigemptyset(&sa_mask);
	sigaddset(&sa_mask, SIGINT);
	sigaddset(&sa_mask, SIGQUIT);
	act.sa_mask = sa_mask;
	act.sa_sigaction = handler_signal;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
}
