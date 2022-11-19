/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:44:41 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/18 16:53:22 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *before, t_list *after)
{
	t_node	*new_before_top;
	t_node	*new_after_top;

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
	vars->top->prev = vars->btm;
	vars->btm->next = vars->top;
	vars->top = vars->top->next;
	vars->btm = vars->btm->next;
	vars->top->prev = NULL;
	vars->btm->next = NULL;
}

void	r_rotate(t_list *vars)
{
	vars->top->prev = vars->btm;
	vars->btm->next = vars->top;
	vars->top = vars->top->prev;
	vars->btm = vars->btm->prev;
	vars->top->prev = NULL;
	vars->btm->next = NULL;
}
