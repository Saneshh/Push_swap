/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:50:18 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/19 02:40:46 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hexa(unsigned long nbr, char *base, int fd)
{
	unsigned long	len_base;

	len_base = ft_str_len(base);
	if (nbr >= len_base)
		ft_put_hexa(nbr / len_base, base, fd);
	ft_putchar(base[nbr % len_base], fd);
}

int	ft_void_hexa(unsigned long n, char *base, int fd)
{
	int	len;

	if (n == 0)
	{
		ft_putstr("(nil)", fd);
		return (5);
	}
	else
	{
		ft_putstr("0x", fd);
		len = ft_count_hexa(n);
		ft_put_hexa(n, base, fd);
		return (len + 2);
	}
}
