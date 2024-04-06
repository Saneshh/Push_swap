/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:00:36 by hsolet            #+#    #+#             */
/*   Updated: 2024/02/22 12:10:59 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrpower(long n)
{
	int			len;
	long int	power;

	len = 0;
	power = 1;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (power);
	while (n)
	{
		n /= 10;
		len ++;
	}
	while (len > 0)
	{
		power *= 10;
		len --;
	}
	return (power / 10);
}

static void	n_negative(unsigned int *nbr, int *n, int *power, int *nbr_temp)
{
	*nbr = *n * -1;
	*nbr_temp = *nbr / *power + '0';
	*n = *nbr % *power;
}

int	ft_putnbr(int n, int fd)
{
	int				len;
	int				power;
	unsigned int	nbr;
	int				nbr_temp;

	len = ft_count_nbr(n);
	power = ft_nbrpower(n);
	while (n || power > 1)
	{
		if (n >= 0)
		{
			nbr_temp = n / power + '0';
			n = n % power;
		}
		else
		{
			write(fd, "-", 1);
			n_negative(&nbr, &n, &power, &nbr_temp);
		}
		power /= 10;
		write(fd, &nbr_temp, 1);
	}
	if (power)
		write(fd, "0", 1);
	return (len);
}
