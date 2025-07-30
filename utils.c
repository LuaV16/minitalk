/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:14:24 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/10 14:24:17 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

void	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar((num % 10) + '0');
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	n;
	int	negative;

	negative = 0;
	n = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			negative = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		n += *nptr - '0';
		if (ft_isdigit(*(nptr + 1)))
			n = n * 10;
		nptr++;
	}
	if (negative == 1)
		n *= -1;
	return (n);
}
