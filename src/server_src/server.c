/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:54:37 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/09 22:46:50 by lcarrizo         ###    ###london.com    */
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
	static int				i = 0;
	static int				pid = 0;
	static char				*message = 0;
	static unsigned char	bit = 0;
	static unsigned char	c = 0;

	(void)ucontext;
	if (info->si_pid)
		pid = info->si_pid;
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
		i = 0;
		c = 0;
	}
	message = print_message(message);
	if (kill(pid, SIGUSR1) == -1)
		write(1, "problema server", 15);
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
