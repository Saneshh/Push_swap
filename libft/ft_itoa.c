/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:24:57 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/06 22:13:45 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
	}
	while (n)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static void	ft_last_digit(int *nb, int *nb_temp)
{
	unsigned int	nbr;

	if (*nb >= 0)
	{
		*nb_temp = *nb % 10 + 48;
		*nb = *nb / 10;
	}
	else
	{
		nbr = *nb * -1;
		*nb_temp = nbr % 10 + 48;
		*nb = nbr / 10;
	}
}

char	*ft_itoa(int n)
{
	int		nb_temp;
	int		i;
	char	*tab;
	int		len;

	len = ft_nbrlen(n);
	tab = malloc(len + 1 * sizeof(char));
	if (tab == NULL)
		return (NULL);
	i = 1;
	if (n < 0)
		tab[0] = '-';
	if (n == 0)
		tab[0] = '0';
	while (n)
	{
		ft_last_digit(&n, &nb_temp);
		tab[len - i] = nb_temp;
		i++;
	}
	tab[len] = '\0';
	return (tab);
}
