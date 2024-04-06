/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:00:20 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/08 17:34:02 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (big == NULL && len == 0)
		return (NULL);
	if (!(little[j]) || little == big)
		return ((char *)big);
	while (big[i])
	{
		if (little[j] == big[j + i] && big[i + j] && (j + i) < len)
			j++;
		else
		{
			i++;
			j = 0;
		}
		if (little[j] == '\0')
			return (((char *)big) + i);
	}
	return (NULL);
}
