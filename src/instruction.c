/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:30 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/24 10:03:01 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *vars)
{
	if (swap(&vars->a) == -1)
		return ;
	ft_printf("sa\n");
}

void	pa(t_info *vars)
{
	if (push(&vars->b, &vars->a) == -1)
		return ;
	ft_printf("pa\n");
}

void	pb(t_info *vars)
{
	if (push(&vars->a, &vars->b) == -1)
		return ;
	ft_printf("pb\n");
}

void	rr(t_info *vars)
{
	if (rotate(&vars->a) == -1 || rotate(&vars->b) == -1)
		return ;
	ft_printf("rr\n");
}

void	rrr(t_info *vars)
{
	if (r_rotate(&vars->a) == -1 || r_rotate(&vars->b) == -1)
		return ;
	ft_printf("rrr\n");
}
