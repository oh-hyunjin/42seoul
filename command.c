/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:44:41 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/08 14:16:25 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	change(t_list **a_top, t_list *a, t_list *b) // a와 b 자리 교체
// {
// 	t_list	temp;

// 	temp.prev = a->prev;
// 	temp.next = a->next;

// 	if (a->prev != NULL)
// 		a->prev->next = b;
// 	else if (a->prev == NULL)
// 		*a_top = b;
// 	a->next->prev = b;
// 	b->prev->next = a;
// 	if (b->next != NULL)
// 		b->next->prev = a;
// 	a->prev = b->prev;
// 	a->next = b->next;
// 	b->prev = temp.prev;
// 	b->next = temp.next;

// 	// printf("a pre: %d, a nex: %d\n", a->prev->num, a->next->num);
// 	// printf("b pre: %d, b nex: %d\n", b->prev->num, b->next->num);
// }

void	swap(t_vars *vars)
{
	t_list	*first;
	t_list	*second;

	first = vars->top;
	second = first->next;
	if (first == NULL || second == NULL)
	{
		printf("< swap fail >\n");
		return ;
	}
	printf("< swap >\n");
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

void	push(t_vars *before, t_vars *after)
{
	t_list	*new_before_top;
	t_list	*new_after_top;

	if (before->top == 0)
	{
		printf("< push fail : before=0 >\n");
		return ;
	}
	printf("< push >\n");
	new_after_top = before->top;
	new_before_top = before->top->next;
	if (new_before_top != NULL)
		(new_before_top)->prev = NULL;
	if (after->top != NULL)
		after->top->prev = new_after_top;
	before->top->next = after->top;
	//
	before->top = new_before_top;
	after->top = new_after_top;
	if (before->top == NULL)
		before->btm = NULL;
	if (after->btm == NULL)
		after->btm = new_after_top;
}

void	rotate(t_vars *vars)
{
	if (vars->top == NULL)
	{
		printf("< rotate fail >\n");
		return ;
	}
	printf("< rotate >\n");
	vars->top->prev = vars->btm;
	vars->btm->next = vars->top;
	vars->top = vars->top->next;
	vars->btm = vars->btm->next;
	vars->top->prev = NULL;
	vars->btm->next = NULL;
}

void	r_rotate(t_vars *vars)
{
	if (vars->top == NULL)
	{
		printf("< reverse rotate fail >\n");
		return ;
	}
	printf("< reverse >\n");
	vars->top->prev = vars->btm;
	vars->btm->next = vars->top;
	vars->top = vars->top->prev;
	vars->btm = vars->btm->prev;
	vars->top->prev = NULL;
	vars->btm->next = NULL;
}
