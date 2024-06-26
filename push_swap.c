/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:46:34 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/22 18:50:39 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_array(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i])
			free(tmp[i++]);
		else
			i++;
	}
	if (tmp)
		free(tmp);
}

static	long int	ft_atol(const char *n)
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
		if (n[i++] == '-')
			sign = -1;
	}
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			return (66666666666);
		res = res * 10 + (n[i++] - '0');
		if ((res > 2147483647 || (res * sign) < -2147483648)
			&& (res * sign) != -2147483648)
			return (66666666666);
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

void	parse_nbr(t_stacks *s, int argc)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(s->args, ' ');
	if (!tmp)
		free(tmp);
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		if ((ft_atol(tmp[i]) == 0 && !ft_strchr(tmp[i], '0'))
			|| ft_atol(tmp[i]) == 66666666666)
		{
			free_array(tmp);
			free_error(s, "Error\n");
		}
		s->a[i] = ft_atol(tmp[i]);
		i++;
	}
	if (tmp)
		free_array(tmp);
	if (i < argc - 1)
		free_error(s, "Error\n");
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	s = ft_calloc(1, sizeof(t_stacks));
	if (s == NULL)
		free_error(s, "Error\n");
	if (argc < 2)
		free_error(s, "");
	join_args(s, argv, argc);
	init_stacks(argc, s);
	parse_nbr(s, argc);
	check_dup(s);
	index_args(s);
	if (!solved(s))
	{
		if (s->a_size == 2 && s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
		else if (s->a_size == 3)
			three_args(s);
		else if (s->a_size == 4 || s->a_size == 5)
			few_args(s);
		else
			radix_sort(s);
	}
	free_error(s, "");
	return (0);
}
