/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:01:41 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/27 22:53:50 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_byte	bytes_received;

void	print_msg(int signal, siginfo_t *info, void *unused)
{
    (void)unused;
	if (signal == SIGUSR1)
		bytes_received.octet = (bytes_received.octet << 1) | 0;
	else if (signal == SIGUSR2)
		bytes_received.octet = (bytes_received.octet << 1) | 1;
	bytes_received.num_of_bits++;
	if (bytes_received.num_of_bits == 8)
	{
        if (bytes_received.octet == '\0')
        {
            ft_putchar('\n');
        }
        else
        {
	        ft_putchar(bytes_received.octet);
        }
		bytes_received.num_of_bits = 0;
		bytes_received.octet = 0;
	}
    kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	bytes_received.num_of_bits = 0;
	bytes_received.octet = 0;
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
