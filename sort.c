/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:46:16 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/22 18:37:28 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	three_args(t_stacks *s)
{
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
	{
		rotate(s->a, s->a_size, "up", "a");
		if (s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
	}
	if (s->a[1] > s->a[0] && s->a[1] > s->a[2])
	{
		rotate(s->a, s->a_size, "down", "a");
		if (s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
	}
	if (s->a[2] > s->a[0] && s->a[2] > s->a[1])
	{
		if (s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
	}
}

void	few_args(t_stacks *s)
{
	int	nbr_elements;

	nbr_elements = s->a_size;
	while (s->a_size != 3)
	{
		if (s->a[0] == 0 || (s->a[0] == 1 && nbr_elements == 5))
			push("pb", s);
		else
			rotate(s->a, s->a_size, "up", "a");
	}
	if (s->b[0] == 0 && nbr_elements == 5)
		swap("sb", s->b, s->b_size);
	three_args(s);
	if (nbr_elements == 5)
		push("pa", s);
	push("pa", s);
}

int	solved(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static	int	get_max_bit(t_stacks *s)
{
	int	i;
	int	max;
	int	max_bit;

	i = 0;
	max_bit = 0;
	max = s->a[0];
	while (i < s->a_size - 1)
	{
		if (s->a[i] > max)
			max = s->a[i];
		i++;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_stacks *s)
{
	int	i;
	int	j;
	int	size;
	int	max_bit;

	max_bit = get_max_bit(s);
	i = -1;
	while (++i <= max_bit)
	{
		j = -1;
		size = s->a_size;
		while (++j < size)
		{
			if (((s->a[0] >> i) & 1) == 0)
				push("pb", s);
			else
				rotate(s->a, s->a_size, "up", "a");
		}
		while (s->b_size != 0)
			push("pa", s);
		if (solved(s))
			free_error(s, "");
	}
}
