/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:20:19 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/11 17:03:46 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign(const char *nptr, int i, int *negative)
{
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			*negative *= -1;
			i++;
		}
		else
			i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	negative;

	i = 0;
	nbr = 0;
	negative = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	i = sign(nptr, i, &negative);
	while (ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr += nptr[i] - '0';
		i++;
	}
	return (nbr * negative);
}
