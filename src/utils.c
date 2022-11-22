/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:03 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/22 09:33:58 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	return (-num);
}

void	all_list_del(t_node *lst)
{
	t_node	*temp;

	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

int	atoi_valid_check(char *str, int *result)
{
	long long	num;
	int			sign;

	if (str == NULL)
		return (-1); // split malloc fail
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
	if (num < -2147483648 || num > 2147483647)
		return (-1);
	*result = sign * num;
	return (1);
}

t_node	*new_add_list(t_node *prev_node, int val)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = val;
	new->index = 0;
	new->prev = prev_node;
	new->next = NULL;
	return (new);
}

void	last_sort(t_info *vars)
{
	int		ra_num;
	int		reverse_flag;
	t_node	*a_node;

	a_node = vars->a.top;
	ra_num = 0;
	reverse_flag = 0;
	while (a_node != NULL)
	{
		if (a_node->index == 0)
			break ;
		a_node = a_node->next;
		ra_num++;
	}
	if (ra_num > vars->a.len / 2)
		reverse_flag = 1;
	while (vars->a.top->index != 0)
	{
		if (reverse_flag != 1)
			ra(vars);
		else
			rra(vars);
		ra_num--;
	}
}
