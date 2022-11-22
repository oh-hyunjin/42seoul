/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:47:44 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/22 15:14:32 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hardcoding(t_info *vars)
{
	int	first;
	int	second;
	int	third;

	while (1)
	{
		first = vars->a.top->index;
		second = vars->a.top->next->index;
		if (vars->a.len < 3)
			third = vars->a.len + vars->b.len + 1;
		else
			third = vars->a.top->next->next->index;
		if (first < second && second < third)
			break ;
		else if (first > second && first > third)
			ra(vars);
		else if (second > first && second > third)
			rra(vars);
		else if (third > first && third > second)
			sa(vars);
	}
}

void	pivot(int len, t_info *vars)
{
	int		pivot_1;
	int		pivot_2;
	t_node	*temp;

	if (len <= 3)
		return ;
	pivot_1 = len / 3 * 2;
	pivot_2 = len / 3;
	while (len-- > 0)
	{
		temp = vars->a.top;
		if (temp->index < pivot_1)
		{
			pb(vars);
			if (temp->index < pivot_2)
				rb(vars);
		}
		else
			ra(vars);
	}
	while (vars->a.len > 3)
		pb(vars);
}

void	indexing(t_list *a)
{
	int		idx;
	int		max_num;
	t_node	*max_node;
	t_node	*temp;

	idx = a->len - 1;
	while (idx >= 0)
	{
		temp = a->top;
		max_num = -2147483648;
		while (temp != NULL)
		{
			if (temp->num > max_num && temp->index == 0)
			{
				max_node = temp;
				max_num = max_node->num;
			}
			temp = temp->next;
		}
		max_node->index = idx;
		idx--;
	}
}

int	parsing(int argc, char *argv[], t_list *a)
{
	char	**split_ret;
	int		i;
	int		t;
	int		val;

	i = 0;
	while (++i < argc)
	{
		split_ret = ft_split(argv[i], ' '); // split fail: 1. mallocfail, 구분자,,?
		if (split_ret == NULL)
			return (-1);
		t = -1;
		while (split_ret[++t] != NULL)
		{
			if (atoi_valid_check(split_ret[t], &val) == -1)
				return (-1);
			if (new_add_list(a, val) == -1)
				return (-1);
			(a->len)++;
		}
		while (--t >= 0)
			free(split_ret[t]);
		free(split_ret);
	}
	return (1);
}

void	setting(t_info *vars) // setting ㅅㅏㄱ제???
{
	vars->a.len = 0;
	vars->b.len = 0;
	vars->a.top = NULL; // 필요 없나?
	vars->a.btm = NULL; // 이것도..
	vars->b.top = NULL;
	vars->b.btm = NULL;
}
