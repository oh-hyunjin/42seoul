/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:36:56 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/24 10:03:16 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *vars)
{
	if (rotate(&vars->a) == -1)
		return ;
	ft_printf("ra\n");
}

void	rb(t_info *vars)
{
	if (rotate(&vars->b) == -1)
		return ;
	ft_printf("rb\n");
}

void	rra(t_info *vars)
{
	if (r_rotate(&vars->a) == -1)
		return ;
	ft_printf("rra\n");
}

void	rrb(t_info *vars)
{
	if (r_rotate(&vars->b) == -1)
		return ;
	ft_printf("rrb\n");
}
