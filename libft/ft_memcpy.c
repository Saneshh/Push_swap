/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:30:26 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/06 19:23:31 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destb;
	char	*srcb;

	destb = ((char *)dest);
	srcb = ((char *)src);
	i = 0;
	if (destb == NULL && srcb == NULL)
		return (NULL);
	while (i < n && (destb[i] != '\0' || srcb[i] != '\0'))
	{
		destb[i] = srcb[i];
		i++;
	}
	return (destb);
}
