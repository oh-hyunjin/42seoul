/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:30 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/23 15:48:33 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_info *vars)
{
	swap(&vars->a);
	swap(&vars->b);
}

void	rr(t_info *vars)
{
	rotate(&vars->a);
	rotate(&vars->b);
}

void	rrr(t_info *vars)
{
	r_rotate(&vars->a);
	r_rotate(&vars->b);
}
