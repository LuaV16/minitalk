/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:57:38 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/30 11:08:23 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_byte
{
	unsigned char	octet;
	int				num_of_bits;
}					t_byte;

void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
int					ft_atoi(const char *nptr);

#endif