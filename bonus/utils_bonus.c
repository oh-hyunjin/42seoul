/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:03 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/23 16:33:21 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	all_list_del(t_info *vars)
{
	t_node	*tar_node;
	t_node	*temp;

	temp = vars->a.top;
	while (temp != NULL)
	{
		tar_node = temp;
		temp = temp->next;
		free(tar_node);
	}
	temp = vars->b.top;
	while (temp != NULL)
	{
		tar_node = temp;
		temp = temp->next;
		free(tar_node);
	}
}

int	atoi_valid_check(t_list *a, char *str, int *result_num)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		sign = -1;
		str++;
	}
	if ('0' > *str || *str > '9')
		return (-1);
	while ('0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - '0');
	if (*str != '\0')
		return (-1);
	num = sign * num;
	if (num < -2147483648 || num > 2147483647)
		return (-1);
	*result_num = num;
	if (duplicate_check(a, *result_num) == -1)
		return (-1);
	return (1);
}

int	duplicate_check(t_list *a, int num)
{
	t_node	*temp;

	temp = a->top;
	while (temp != NULL)
	{
		if (temp->num == num)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

int	new_add_list(t_list *a, int val)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (-1);
	new->prev = a->btm;
	new->next = NULL;
	new->num = val;
	new->index = 0;
	if (a->top == NULL)
		a->top = new;
	else
		a->btm->next = new;
	a->btm = new;
	return (1);
}
