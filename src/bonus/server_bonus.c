/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:54:37 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/19 18:42:10 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/* decodes each signal that arrives.
 * it obtains the entire message and prints it  */
static void	decode_signal(int signum, int *ready, char **message)
{
	static int				i = 0;
	static int				n = 0;
	static unsigned char	c = 0;

	if (signum == SIGUSR2)
		c += 1 << i;
	if (++i == 8)
	{
		add_char(c, message, n);
		n++;
		if (c == '\0')
		{
			ft_printf("%s\n", *message);
			free(*message);
			*message = NULL;
			n = 0;
		}
		i = 0;
		c = 0;
	}
	*ready = 1;
	if (n == 0 && i == 0)
		*ready = 0;
}

/* Handle the signal recived and acts depending on which one is received */
static void	handler_signal_server(int signum, siginfo_t *info, void *ucontext)
{
	static int	pid = 0;
	static int	server_ready = 1;
	static char	*message = NULL;

	(void)ucontext;
	if (info->si_pid)
		pid = info->si_pid;
	if (server_ready == 1)
	{
		server_ready = 0;
		decode_signal(signum, &server_ready, &message);
	}
	if (server_ready == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			error("Server communication with the client failed", message);
			kill(SIGUSR2, pid);
		}
	}
	else if (server_ready == 0)
	{
		kill(pid, SIGUSR2);
		server_ready = 1;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	act;
	sigset_t			sa_mask;

	if (argc != 1 || argv[1])
		error("Use: < ./server >\n", NULL);
	act.sa_handler = 0;
	sigemptyset(&sa_mask);
	sigaddset(&sa_mask, SIGINT);
	sigaddset(&sa_mask, SIGQUIT);
	act.sa_mask = sa_mask;
	act.sa_sigaction = handler_signal_server;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
