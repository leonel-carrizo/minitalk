/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:54:17 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/18 22:01:41 by lcarrizo         ###   ########.fr       */
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

/* Send a signal for each bit of char c to the PID. 
 * When it has sent 1 byte, reset the number of bits sent. */
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

/* convert the message to binary and send a signal to the server bit to bit */
static int	send_bits(char *message, int pid, int *str_end)
{
	static int		c_pid;
	static int		b = 0;
	static char		*str = NULL;

	if (message)
		str = ft_strdup((const char *)message);
	if (!str)
		return (0);
	if (pid)
		c_pid = pid;
	if (str[b])
	{
		if (send_signal(str[b], c_pid, &b) == 1)
			error("Connection Error: Check the PID.\n", str);
		return (0);
	}
	if (!send_null(c_pid, str, str_end) && *str_end == 1)
		return (1);
	return (0);
}

/* Establishes how the signals that arrive as feedback from the server
 * should be processed */
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

	if (argc != 3 || !ft_isnumeric (argv[1]))
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
