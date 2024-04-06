/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:29:45 by hsolet            #+#    #+#             */
/*   Updated: 2024/02/22 12:12:23 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", fd);
		return (6);
	}
	else
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	return (ft_str_len(s));
}
