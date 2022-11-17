/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:44:41 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/17 11:20:33 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *vars)
{
	t_node	*first;
	t_node	*second;

	first = vars->top;
	second = first->next;
	if (first == NULL || second == NULL)
	{
		// printf("< swap fail >\n");
		return ;
	}
	if (vars->name == 'a')
		printf("sa\n");
	else
		printf("sb\n");
	// printf(", %d\n", vars->top->num);
	first->next = second->next;
	first->prev = second;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	vars->top = second;
	if (first->next == NULL)
		vars->btm = first;
}

void	push(t_list *before, t_list *after)
{
	t_node	*new_before_top;
	t_node	*new_after_top;

	if (before->top == 0)
	{
		// printf("< push fail : before=0 >\n");
		return ;
	}
	if (after->name == 'a')
		printf("pa <%d>\n", before->top->index);
	else
		printf("pb <%d>\n", before->top->index);
	// printf(", %d\n", before->top->num);
	new_after_top = before->top;
	new_before_top = before->top->next;
	if (new_before_top != NULL)
		(new_before_top)->prev = NULL;
	if (after->top != NULL)
		after->top->prev = new_after_top;
	before->top->next = after->top;
	before->top = new_before_top;
	after->top = new_after_top;
	if (before->top == NULL)
		before->btm = NULL;
	if (after->btm == NULL)
		after->btm = new_after_top;
	before->len--;
	after->len++;
}

void	rotate(t_list *vars) // index로 해야 하나??
{
	if (vars->top == NULL)
	{
		// printf("< rotate fail >\n");
		return ;
	}
	if (vars->len == 1)
		return ;
	if (vars->name == 'a')
		printf("ra <%d>\n", vars->top->index);
	else
		printf("rb <%d>\n", vars->top->index);
	// printf(", %d\n", vars->top->num);
	vars->top->prev = vars->btm;
	vars->btm->next = vars->top;
	vars->top = vars->top->next;
	vars->btm = vars->btm->next;
	vars->top->prev = NULL;
	vars->btm->next = NULL;
}

void	r_rotate(t_list *vars)
{
	if (vars->top == NULL)
	{
		// printf("< reverse rotate fail >\n");
		return ;
	}
	if (vars->len == 1)
		return ;
	if (vars->name == 'a')
		printf("rra <%d>\n", vars->btm->index);
	else
		printf("rrb <%d>\n", vars->btm->index);
	// printf(", %d\n", vars->top->num);
	vars->top->prev = vars->btm;
	vars->btm->next = vars->top;
	vars->top = vars->top->prev;
	vars->btm = vars->btm->prev;
	vars->top->prev = NULL;
	vars->btm->next = NULL;
}
