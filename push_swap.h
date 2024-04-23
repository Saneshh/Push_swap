/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:47:36 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/06 10:21:09 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*args;
}	t_stacks;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		three_args(t_stacks *s);
void		few_args(t_stacks *s);
void		radix_sort(t_stacks *s);
void		join_args(t_stacks *s, char **argv, int argc);
void		init_stacks(int argc, t_stacks *s);
void		index_args(t_stacks *s);
void		check_dup(t_stacks *s);
void		parse_nbr(t_stacks *s, int argc);
void		free_error(t_stacks *s, char *str);
int			solved(t_stacks	*s);

#endif
