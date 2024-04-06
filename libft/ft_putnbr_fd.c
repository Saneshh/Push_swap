/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:00:36 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/06 22:14:29 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrpower(long n)
{
	long int	len;
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

void	ft_putnbr_fd(int n, int fd)
{
	int				power;
	unsigned int	nbr;
	int				nbr_temp;

	power = ft_nbrpower(n);
	while (n || power > 1)
	{
		if (n >= 0)
		{
			nbr_temp = n / power + 48;
			n = n % power;
		}
		else
		{
			nbr = -n;
			write(fd, "-", 1);
			nbr_temp = nbr / power + 48;
			n = nbr % power;
		}
		power /= 10;
		write(fd, &nbr_temp, 1);
	}
	if (power)
		write(fd, "0", 1);
}
