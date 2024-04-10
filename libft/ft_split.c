/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:07:42 by hsolet            #+#    #+#             */
/*   Updated: 2023/11/11 17:48:48 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nbr_word(char const *s, char c)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				i++;
			}
			len ++;
		}
		while (s[i] == c && s[i])
		{
			i++;
		}
	}
	return (len);
}

static char	*fct_split(char const *s, char c, size_t *i, char *str)
{
	int	j;

	j = 0;
	while (*i < ft_strlen(s))
	{
		if (s[*i] != c)
		{
			str[j] = s[*i];
			*i += 1;
			j += 1;
		}
		else if (s[*i] == c && (*i == 0 || s[*i - 1] != c))
		{
			str[j] = '\0';
			*i += 1;
			return (str);
		}
		else
			*i += 1;
	}
	str[j] = '\0';
	return (str);
}

static size_t	ft_len_word(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i += 1;
	}
	return (len);
}

static void	*ft_free_all(char **str, int len)
{
	while (len >= 0)
	{
		free(str[len]);
		len--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	str = ft_calloc ((ft_nbr_word(s, c) + 1), sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (i < ft_nbr_word(s, c))
	{
		while (s[j] == c && s[j])
		{
			j += 1;
		}
		str[i] = ft_calloc ((ft_len_word(s, c, j) + 1), sizeof(char));
		if (str[i] == NULL)
			return (ft_free_all(str, ft_nbr_word(s, c)));
		str[i] = fct_split(s, c, &j, str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
