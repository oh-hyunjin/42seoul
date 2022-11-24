/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:08:37 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/24 09:58:46 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_together(t_info *vars, int *ra_num, int *rb_num)
{
	while (*ra_num > 0 && *rb_num > 0)
	{
		rr(vars);
		(*ra_num)--;
		(*rb_num)--;
	}
	while (*ra_num < 0 && *rb_num < 0)
	{
		rrr(vars);
		(*ra_num)++;
		(*rb_num)++;
	}
}

void	rotate_before_push(t_info *vars, int ra_num, int rb_num)
{
	if ((ra_num < 0 && rb_num < 0) || (ra_num > 0 && rb_num > 0))
		rotate_together(vars, &ra_num, &rb_num);
	while (rb_num > 0)
	{
		rb(vars);
		rb_num--;
	}
	while (rb_num < 0)
	{
		rrb(vars);
		rb_num++;
	}
	while (ra_num > 0)
	{
		ra(vars);
		ra_num--;
	}
	while (ra_num < 0)
	{
		rra(vars);
		ra_num++;
	}
}

int	is_min(t_node *b, t_node *min, t_rotateNum rotate_cnt, t_info vars)
{
	b->ra_num = rotate_cnt.ra;
	b->rb_num = rotate_cnt.rb;
	if (rotate_cnt.ra > vars.a.len / 2)
		b->ra_num = rotate_cnt.ra - vars.a.len;
	if (rotate_cnt.rb > vars.b.len / 2)
		b->rb_num = rotate_cnt.rb - vars.b.len;
	if ((ft_abs(b->ra_num) + ft_abs(b->rb_num)) \
			< (ft_abs(min->ra_num) + ft_abs(min->rb_num)))
		return (1);
	return (0);
}

void	get_min_instruction(t_info *vars, t_node **min)
{
	t_node		*a;
	t_node		*b;
	t_rotateNum	rotate_cnt;

	b = vars->b.top;
	rotate_cnt.rb = 0;
	while (b != NULL)
	{
		a = vars->a.top;
		rotate_cnt.ra = 1;
		while (a->next != NULL)
		{
			if ((a->index < b->index && b->index < a->next->index) \
			|| (b->index < a->next->index && a->next->index < a->index) \
			|| (a->next->index < a->index && a->index < b->index))
				break ;
			a = a->next;
			rotate_cnt.ra++;
		}
		if (is_min(b, *min, rotate_cnt, *vars))
			*min = b;
		b = b->next;
		rotate_cnt.rb++;
	}
}

void	greedy(t_info *vars)
{
	t_node	*min;

	while (vars->b.len != 0)
	{
		min = vars->b.top;
		get_min_instruction(vars, &min);
		rotate_before_push(vars, min->ra_num, min->rb_num);
		pa(vars);
	}
}
