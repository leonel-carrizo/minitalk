/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:54:17 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/18 14:40:21 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/* send a NULL carcter represented as a binary number */
static int	send_null(int pid, char *str, int *str_end)
{
	static int	i = 0;

	if (++i <= 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			error("Error sending signal to server.\n", str);
		if (i == 8)
		{
			free(str);
			*str_end = 1;
			return (0);
		}
		return (1);
	}
	return (0);
}

static int	send_signal(char c, int pid, int *b)
{
	static int	i = 0;
	
	if ((c >> i) & 1)
	{
		if ((kill(pid, SIGUSR2) == -1))
			return (1);
		i++;
		if (i == 8)
		{
			*b = *b + 1;
			i = 0;
		}
		return (0);
	}
	else if (kill(pid, SIGUSR1) == -1)
		return (1);
	i++;
	if (i == 8)
	{
		*b = *b + 1;
		i = 0;
	}
	return (0);
}

/*
01101000 -> 00010110 = h 01101111 -> 11110110 = o 01101100 -> 00110110 = l 
01100001 -> 10000110 = a */
/* convert the message to binary and send a signal to the server bit to bit */
static int	send_bits(char *message, int pid, int *str_end)
{
	static	int			c_pid;
	static int			b = 0;
	static char	*str = NULL;

	if (message)
		str = ft_strdup((const char *)message);
	if (!str)
		return (0);
	if (pid)
		c_pid = pid;
	if (str[b])
	{
		if (send_signal(str[b], c_pid, &b) == 1)
			error("Error trying to connect: Check the PID.\n", str);
		return (0);
	}
	if (!send_null(c_pid, str, str_end) && *str_end == 1)
		return (1);
	return (0);
}

static void	handler_signal_client(int signum)
{
	static int	str_end = 0;

	if (signum == SIGUSR1 && str_end == 0)
		str_end = send_bits(NULL, 0, &str_end);
	else if (signum == SIGUSR2 && str_end == 0)
	{
		write(2, "Comunication with the server lost.\n", 35);
		exit(EXIT_FAILURE);
	}
	else if (signum == SIGUSR2 && str_end)
	{
		write(1, "Message delivered successfuly.\n", 31);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	int			pid;
	char		*message;

	if (argc != 3)
	{
		ft_putstr_fd("Use: <SEVER PID> <STRING MESSAGE>\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handler_signal_client);
	signal(SIGUSR2, handler_signal_client);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	send_bits(message, pid, 0);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
