/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:49:07 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/11 19:38:52 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	startlen(char const *s1, char const *set)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < ft_strlen(set) && s1[i])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	ft_endlen(char const *s1, char const *set, int s1len)
{
	size_t	j;

	j = 0;
	while (j < ft_strlen(set) && s1len > 0)
	{
		if (s1[s1len] == set[j] && s1len)
		{
			s1len--;
			j = 0;
		}
		else
			j++;
	}
	return (s1len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		start;
	char	*str;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	start = startlen(s1, set);
	if (!s1[start])
		return (ft_calloc(1, 1));
	end = ft_endlen(s1, set, ft_strlen(s1) - 1);
	if (start <= end)
	{
		str = ft_calloc(((end - start) + 2), sizeof(char));
		if (str == NULL)
			return (NULL);
		while ((start + i) <= end)
		{
			str[i] = s1[i + start];
			i++;
		}
		return (str);
	}
	return (NULL);
}
