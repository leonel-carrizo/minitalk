/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:54:37 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/13 22:54:43 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

static void	add_char(char c, char **str, size_t n_sig)
{
	int	len;
	char	*temp;

	write(1, &c, 1);
	if (*str)
		len = ft_strlen(*str);
	else
		len = 0;
	temp = (char *)malloc((len + n_sig + 1) * sizeof(char));
	if (!temp)
	{
		free(*str);
		return ;
	}
	if (*str)
		ft_strncpy(temp, *str, len);
	temp[len] = c;
	temp[len + 1] = '\0';
	if (*str)
		free(*str);
	*str = temp;
//	ft_printf("%s", temp);
}

static void	decode_signal(int signum, int *ready)
{
	static int				i = 0;
	static char				*message = NULL;
	static unsigned char	bit = 0;
	static unsigned char	c = 0;

	if (signum == SIGUSR2)
	{
		bit = 1 << i;
		c += bit;
	}
	i++;
	if (i == 8)
	{
		add_char(c, &message, 1);
		i = 0;
		c = 0;
	}
	ft_printf("decode: %s", message);
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
		if (kill(pid, SIGUSR1) == -1)
			write(1, "problema server", 15);
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
