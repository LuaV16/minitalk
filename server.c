/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:01:41 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/30 11:04:41 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_byte	g_bytes_received;

void	print_msg(int signal, siginfo_t *info, void *unused)
{
	(void)unused;
	if (signal == SIGUSR1)
		g_bytes_received.octet = (g_bytes_received.octet << 1) | 0;
	else if (signal == SIGUSR2)
		g_bytes_received.octet = (g_bytes_received.octet << 1) | 1;
	g_bytes_received.num_of_bits++;
	if (g_bytes_received.num_of_bits == 8)
	{
		if (g_bytes_received.octet == '\0')
		{
			ft_putchar('\n');
		}
		else
		{
			ft_putchar(g_bytes_received.octet);
		}
		g_bytes_received.num_of_bits = 0;
		g_bytes_received.octet = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	g_bytes_received.num_of_bits = 0;
	g_bytes_received.octet = 0;
	pid = getpid();
	ft_putstr("Servidor iniciado. PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	sa.sa_sigaction = print_msg;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
