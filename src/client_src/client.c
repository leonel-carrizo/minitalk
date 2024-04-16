/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:54:17 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/16 23:14:54 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/* send a NULL carcter represented as a binary number */
static void	send_null(int pid)
{
	int	i;

	i = -1;
	if (++i < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			return ;
	//	usleep(800);
	}
}

/* convert a char to binary number */
static unsigned int	bit(char c)
{
	static int	i = 0;
	unsigned int	bit;

	bit = ((c >> i) & 1);
	i++;
	return (bit);
}

/*
01101000 -> 00010110 = h 01101111 -> 11110110 = o 01101100 -> 00110110 = l 
01100001 -> 10000110 = a */
/* convert the message to binary and send a signal to the server bit to bit */
static int	sent_message(char *message, int pid)
{
	static	int			c_pid;
	static int			b = 0;
	static char	*str;

	str = ft_strdup((const char *)message);
	if (!str)
		return (0);
	c_pid = pid;
	if (str[b])
	{
		if (bit(str[b]) == 1)
		{
			if ((kill(c_pid, SIGUSR2) == -1))
				error("Error sending signal", str); 
		}
		else if (kill(c_pid, SIGUSR1) == -1)
				error("Error sending signal", str);
		return (0);
		b++;
	}
	if (str[b] == '\0')
		send_null(c_pid);
	free(str);
	return (1);
}

void	handler_sig_client(int signum)
{
	int	end;

	end = 0;
	if (signum == SIGUSR1)
		end = sent_message(0, 0);
	else if (signum == SIGUSR2)
		write(1, "signal SIGUSR2 form sever", 25);
	if (end)
	{
		ft_printf("Message delivered successfuly.\n");
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
	signal(SIGUSR1, handler_sig_client);
	signal(SIGUSR2, handler_sig_client);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	sent_message(message, pid);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
