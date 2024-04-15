/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:54:37 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/15 23:23:58 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

static void	add_char(char c, char **str)
{
	static int	len = 0;
	int		i;
	int		j;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return ;
	i = len;
	j = 0;
	while (i >= 0 && *str[j])
	{
		temp[j] = *str[j];
		i--;
		j++;
	}
	temp[len] = c;
	len++;
	if (*str)
		free(*str);
	*str = temp;
}

static void	decode_signal(int signum, int *ready)
{
	static int				i = 0;
	static char				*message = NULL;
	static unsigned char	bit = 0;
	static unsigned char	c = 0;
	static int	n = 0;

	if (signum == SIGUSR2)
	{
		bit = 1 << i;
		c += bit;
	}
	i++;
	if (i == 8)
	{
		add_char(c, &message);
		n++;
		if (c == '\0')
		{
			write(1, message, n);
			free(message);
			message = NULL;
			n = 0;
			//return ;
		}
		i = 0;
		c = 0;
	}
	*ready = 1;
}

/* Handle the signal recived and acts depending on which one is received */
void	handler_signal(int signum, siginfo_t *info, void *ucontext)
{
	static int	pid = 0;
	static	int	server_ready = 1;

	(void)ucontext;
	if (info->si_pid)
		pid = info->si_pid;
	if (server_ready == 1)
	{
		server_ready = 0;
		decode_signal(signum, &server_ready);
	}
	if (server_ready == 1)
	{
		(void)pid;
		//if (kill(pid, SIGUSR1) == -1)
		//	write(1, "problema server", 15);
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
	return (EXIT_SUCCESS);
}
