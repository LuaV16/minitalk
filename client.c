/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:10:48 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/11 12:28:37 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_to_server(int pid, char c)
{
    int bit;

    bit = 7;
    while(bit >= 0)
    {
        if (c >> bit & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(100);
        bit--;
    }
}

int main(int argc, char *argv[])
{
    int pid;
    char *msg;
    
    if (argc != 3)
    {
        ft_putstr("Error! Please, use ./client <PID> <message>\n");
        return (1);
    }
    pid = ft_atoi(argv[1]);
    msg = argv[2];

    while(*msg != '\0')
    {
        send_to_server(pid, *msg);
        msg++;
    }
}