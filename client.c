/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:10:48 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/30 11:02:33 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	change_ack(int signal)
{
	(void)signal;
	g_ack_received = 1;
}

void	send_to_server(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if (c >> bit & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack_received)
		{
			usleep(50);
		}
		bit--;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		ft_putstr("Error! Please, use ./client <PID> <message>\n");
		return (1);
	}
	signal(SIGUSR1, change_ack);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (*msg != '\0')
	{
		send_to_server(pid, *msg);
		msg++;
	}
	send_to_server(pid, '\0');
	return (0);
}
