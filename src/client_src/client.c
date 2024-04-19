/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:54:17 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/19 12:53:44 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/* send a NULL carcter represented as a binary number */
static void	send_null(int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			return ;
		usleep(1500);
	}
}

/* convert the message to binary and send a signal to the server bit to bit */
static void	sent_message(char *message, int pid)
{
	int			nbr[8];
	int			j;
	static int	i;
	static char	*str;

	str = message;
	i = 0;
	while (str[i])
	{
		char_to_bin(str[i], nbr);
		j = -1;
		while (++j < 8)
		{
			if (nbr[j] == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					error("Error: Check the PID", NULL);
			}
			else if (nbr[j] == 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					error("Error: Check the PID", NULL);
			}
			usleep(1500);
		}
		i++;
		if (str[i] == '\0')
			send_null(pid);
	}
}

void	handler_sig_client(int signum)
{
	if (signum == SIGUSR1)
		(void)signum;
	else
		(void)signum;
}

int	main(int argc, char *argv[])
{
	int			pid;
	char		*message;

	if (argc != 3 || !ft_isnumeric(argv[1]))
	{
		ft_putstr_fd("Use: <SEVER PID> <STRING MESSAGE>\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handler_sig_client);
	signal(SIGUSR2, handler_sig_client);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	sent_message(message, pid);
	return (EXIT_SUCCESS);
}
