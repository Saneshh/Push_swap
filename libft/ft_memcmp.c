/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:36:07 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/16 14:58:46 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1b;
	char	*s2b;

	s1b = ((char *)s1);
	s2b = ((char *)s2);
	i = 0 ;
	if (n == 0 || s1 == s2)
		return (0);
	while (i < (n - 1) && (s1b[i] == s2b[i]))
		i++;
	return (((unsigned char *)s1b)[i] - ((unsigned char *)s2b)[i]);
}
