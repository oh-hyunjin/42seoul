/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:44:41 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/24 09:58:03 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap(t_list *vars)
{
	t_node	*first;
	t_node	*second;

	first = vars->top;
	second = first->next;
	if (first == NULL || second == NULL)
		return (-1);
	first->next = second->next;
	first->prev = second;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	vars->top = second;
	if (first->next == NULL)
		vars->btm = first;
	return (1);
}

int	push(t_list *before, t_list *after)
{
	t_node	*new_before_top;
	t_node	*new_after_top;

	if (before->top == NULL)
		return (-1);
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
	return (1);
}

int	rotate(t_list *vars)
{
	if (vars->top == NULL || vars->len == 1)
		return (-1);
	vars->top->prev = vars->btm;
	vars->btm->next = vars->top;
	vars->top = vars->top->next;
	vars->btm = vars->btm->next;
	vars->top->prev = NULL;
	vars->btm->next = NULL;
	return (1);
}

int	r_rotate(t_list *vars)
{
	if (vars->top == NULL || vars->len == 1)
		return (-1);
	vars->top->prev = vars->btm;
	vars->btm->next = vars->top;
	vars->top = vars->top->prev;
	vars->btm = vars->btm->prev;
	vars->top->prev = NULL;
	vars->btm->next = NULL;
	return (1);
}
