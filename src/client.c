/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:54:17 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/08 22:49:25 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/* convert a char to binary number */
static void	char_to_bin(char c, int nbr[])
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		nbr[i] = (c >> i) & 1;
		i++;
	}

}

/* convert the message to binary and send a signal to the server bit to bit */
static void	sent_message(char *message, int pid)
{
	static char	*str;
	static int	nbr[8];
	static int	i;
	static int	j;

	str = message;
	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		char_to_bin(str[i], nbr);
		j = -1;
		while (++j <= 7)
		{
			if (nbr[j] == 0)
				kill(pid, SIGUSR1);
			else if (nbr[j] == 1)
				kill(pid, SIGUSR2);
			usleep(200);
		}
		i++;
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
	pid = ft_atoi(argv[1]);
	message = argv[2];
	sent_message(message, pid);
	return (EXIT_SUCCESS);
}
