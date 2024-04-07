/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:46:16 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/06 12:17:57 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
void	three_args(t_stacks *s)
{
	if (s->a[2] < s->a[0] && s->a[2] < s->a[1])
	{
		if (s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
		rotate(s->a, s->a_size, "down", "a");
	}
	else if (s->a[2] > s->a[0] && s->a[2] > s->a[1])
	{
		if (s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
	}
	else if ((s->a[0] < s->a[1] && s->a[0] > s->a[2])
		|| (s->a[0] > s->a[1] && s->a[0] < s->a[2]))
	{
		if (s->a[0] < s->a[1])
			swap("sa", s->a, s->a_size);
		rotate(s->a, s->a_size, "up", "a");
	}
}*/

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
	while (s->a_size != 3 && !solved(s))
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
/*
static void	radix_sort_resolve(t_stacks *s, int size, int bit_size, int j)
{
	int	b_elements;

	b_elements = s->b_size;
	while (size && !solved(s))
	{
		if (((s->a[0] >> j) & 1) == 0)
			push("pb", s);
		else
			rotate(s->a, s->a_size, "up", "a");
		size--;
	}
	while (b_elements && j <= bit_size && !solved(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			rotate(s->b, s->b_size, "up", "b");
		else
			push("pa", s);
		b_elements--;
	}
	if (solved(s))
		while (s->b_size != 0)
			push("pa", s);
}

void	radix_sort(t_stacks *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 1;
	size = s->a_size;
	while (size > 1 && bit_size)
	{
		size /= 2;
		bit_size++;
	}
	j = 0;
	while (j <= bit_size)
	{
		size = s->a_size;
		radix_sort_resolve(s, size, bit_size, j + 1);
		j++;
	}
	while (s->b_size != 0)
		push("pa", s);
}*/

static void radix_sort_resolve(t_stacks *s, int bit_size, int size)
{
	int	i;
	int	size_b;

	i = 0;
	while (i < size)
	{
		if (((s->a[0] >> bit_size) & 1) == 0)
			push("pb", s);
		else
			rotate(s->a, s->a_size, "up", "a");
		i++;
	}
	i = 0;
	size_b = s->b_size;
	while (s->b_size > 0 && i < size_b)
	{
		if (((s->b[0] >> (bit_size * 2)) & 1) == 0)
			rotate(s->b, s->b_size, "up", "b");
		else
			push("pa", s);
		i++;
	}
		if (solved(s))
			while (s->b_size != 0)
				push("pa", s);

}

void radix_sort(t_stacks *s)
{
	int	bit_size;
	int	size;

	bit_size = 1;
	while (solved(s) != 1)
	{
		size = s->a_size;
		radix_sort_resolve(s, bit_size, size);
		bit_size++;
	}
}
