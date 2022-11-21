/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:30 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/21 09:20:58 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *vars)
{
	t_node	*first;
	t_node	*second;

	first = vars->a.top;
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
	vars->a.top = second;
	if (first->next == NULL)
		vars->a.btm = first;
}

void	pa(t_info *vars)
{
	if (vars->b.top == 0)
		return ;
	printf("pa\n");
	push(&vars->b, &vars->a);
}

void	pb(t_info *vars)
{
	if (vars->a.top == 0)
		return ;
	printf("pb\n");
	push(&vars->a, &vars->b);
}

void	ra(t_info *vars)
{
	if (vars->a.top == NULL || vars->a.len == 1)
		return ;
	printf("ra\n");
	rotate(&vars->a);
}

void	rb(t_info *vars)
{
	if (vars->b.top == NULL || vars->b.len == 1)
		return ;
	printf("rb\n");
	rotate(&vars->b);
}

void	rr(t_info *vars)
{
	if (vars->a.top == NULL || vars->a.len == 1)
		return ;
	if (vars->b.top == NULL || vars->b.len == 1)
		return ;
	printf("rr\n");
	rotate(&vars->a);
	rotate(&vars->b);
}

void	rra(t_info *vars)
{
	if (vars->a.top == NULL || vars->a.len == 1)
		return ;
	printf("rra\n");
	r_rotate(&vars->a);
}

void	rrb(t_info *vars)
{
	if (vars->b.top == NULL || vars->b.len == 1)
		return ;
	printf("rrb\n");
	r_rotate(&vars->b);
}

void	rrr(t_info *vars)
{
	if (vars->a.top == NULL || vars->a.len == 1)
		return ;
	if (vars->b.top == NULL || vars->b.len == 1)
		return ;
	printf("rrr\n");
	r_rotate(&vars->a);
	r_rotate(&vars->b);
}