/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:18:09 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/10 18:03:21 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*stcat;
	size_t	len1;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	stcat = malloc ((len1 + ft_strlen(s2) + 1) * sizeof(char));
	if (stcat == NULL)
		return (NULL);
	while (i < len1)
	{
		stcat[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		stcat[len1 + i] = s2[i];
		i++;
	}
	stcat[len1 + ft_strlen(s2)] = '\0';
	return (stcat);
}
