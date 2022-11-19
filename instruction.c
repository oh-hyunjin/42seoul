/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:30 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/19 12:57:11 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *vars)
{
	t_node	*first;
	t_node	*second;

	first = vars->top;
	second = first->next;
	if (first == NULL || second == NULL)
		return ;
	printf("sa\n");
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

void	pa(t_list *a, t_list *b)
{
	if (a->top == 0)
		return ;
	printf("pa\n");
	push(a, b);
}

void	pb(t_list *b, t_list *a)
{
	if (b->top == 0)
		return ;
	printf("pb\n");
	push(b, a);
}

void	ra(t_list *vars)
{
	if (vars->top == NULL || vars->len == 1)
		return ;
	printf("ra\n");
	rotate(vars);
}

void	rb(t_list *vars)
{
	if (vars->top == NULL || vars->len == 1)
		return ;
	printf("rb\n");
	rotate(vars);
}

void	rr(t_list *a, t_list *b)
{
	if (a->top == NULL || a->len == 1)
		return ;
	if (b->top == NULL || b->len == 1)
		return ;
	printf("rr\n");
	rotate(a);
	rotate(b);
}

void	rra(t_list *vars)
{
	if (vars->top == NULL || vars->len == 1)
		return ;
	printf("rra\n");
	r_rotate(vars);
}

void	rrb(t_list *vars)
{
	if (vars->top == NULL || vars->len == 1)
		return ;
	printf("rrb\n");
	r_rotate(vars);
}

void	rrr(t_list *a, t_list *b)
{
	if (a->top == NULL || a->len == 1)
		return ;
	if (b->top == NULL || b->len == 1)
		return ;
	printf("rrr\n");
	r_rotate(a);
	r_rotate(b);
}