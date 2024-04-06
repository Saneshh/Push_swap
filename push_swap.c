/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:46:34 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/06 12:27:32 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_atol(const char *n, t_stacks *s)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(n) > 11)
			free_error(s, "Error\n");
		if (!(n[i] >= '0' && n[i] <= '9'))
			free_error(s, "Error\n");
		res = res * 10 + (n[i++] - '0');
	}
	return ((int)(res * sign));
}

void	join_args(t_stacks *s, char **argv, int argc)
{
	char	*tmp2;
	int		i;
	char	*tmp;
	char	*tmp3;

	i = 1;
	tmp2 = ft_strdup("");
	while (i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		free(tmp2);
		tmp2 = tmp;
		if (i != argc - 1)
		{
			tmp3 = ft_strjoin(tmp2, " ");
			free(tmp2);
			tmp2 = tmp3;
		}
		i++;
	}
	s->args = ft_strdup(tmp2);
	if (s->args == NULL)
		free_error(s, "Error\n");
	free(tmp2);
}

void	parse_nbr(t_stacks *s)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(s->args, ' ');
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		if (ft_atol(tmp[i], s) == 0 && ft_strncmp(tmp[i], "0", 1))
			free_error(s, "Error\n");
		s->a[i] = ft_atol(tmp[i], s);
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	free_error(t_stacks *s, char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->args != NULL)
			free(s->args);
		if (s != NULL)
			free(s);
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	int i;

	i = 0;
	s = malloc(sizeof(t_stacks));
	join_args(s, argv, argc);
	init_stacks(argc, s);
	parse_nbr(s);
	check_dup(s);
	index_args(s);
	while(i < s->a_size)
	{
		ft_printf("%d", s->a[i]);
		i++;
	}
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		three_args(s);
	else if (s->a_size == 4 || s->a_size == 5)
		few_args(s);
	else
		radix_sort(s);
	solved(s);
	free_error(s, "");
	return (0);
}
