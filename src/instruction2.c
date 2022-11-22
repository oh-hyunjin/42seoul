/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:36:56 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/21 09:39:10 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
