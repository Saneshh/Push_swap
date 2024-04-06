/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:15:11 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/17 19:36:21 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base, int fd)
{
	size_t	len_base;
	int		len;

	len_base = ft_str_len(base);
	if (len_base == 16)
		len = ft_count_hexa(nbr);
	else
		len = ft_count_nbr(nbr);
	if (nbr >= len_base)
		ft_putnbr_base(nbr / len_base, base, fd);
	ft_putchar(base[nbr % len_base], fd);
	return (len);
}
