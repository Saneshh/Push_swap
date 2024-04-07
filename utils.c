/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:46:54 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/07 15:47:20 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_stacks *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->a_size)
	{
		j = i + 1;
		while (j < s->a_size)
		{
			if (s->a[i] == s->a[j])
				free_error(s, "Error\n");
			j++;
		}
		i++;
	}
}

int	*index_count(t_stacks *s, int i, int *tmp_a)
{
	int	j;
	int	k;

	while (i < s->a_size)
	{
		k = 0;
		j = 0;
		while (j < s->a_size)
		{
			if (s->a[i] > s->a[j])
				k++;
			j++;
		}
		tmp_a[i] = k;
		i += 1;
	}
	return (tmp_a);
}

void	index_args(t_stacks *s)
{
	int	*tmp_a;
	int	i;

	i = 0;
	tmp_a = malloc(s->a_size * sizeof(int));
	if (tmp_a == NULL)
		free_error(s, "Error\n");
	tmp_a = index_count(s, i, tmp_a);
	i = s->a_size - 1;
	while (i >= 0)
	{
		s->a[i] = tmp_a[i];
		i--;
	}
	if (tmp_a)
		free(tmp_a);
}

static int	ft_nbr_word(char const *s, char c)
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
				i++;
			len++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (len);
}

void	init_stacks(int argc, t_stacks *s)
{
	if (argc < 2)
		free_error(s, "Error\n");
	s->a_size = 0;
	argc -= 1;
	if (ft_nbr_word(s->args, ' '))
		s->a_size += ft_nbr_word(s->args, ' ');
	else
		free_error(s, "Error\n");
	s->a = ft_calloc(s->a_size, sizeof(int));
	if (s->a == NULL)
		free_error(s, "Error\n");
	s->b = ft_calloc(s->a_size, sizeof(int));
	if (s->b == NULL)
		free_error(s, "Error\n");
}
