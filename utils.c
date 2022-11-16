/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:03 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/14 10:19:30 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_list_del(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(temp);
	}
}

t_list	*find_list(t_list *top, int num)
{
	t_list	*temp;

	temp = top;
	while (temp != NULL)
	{
		if (temp->num == num)
			return (temp);
		temp = temp->next;
	}
	// printf("cant find\n");
	return (top);
}

int atoi_valid_check(char *str, int *result)
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
	{
		// printf("invalid 1\n");
		return (-1);
	}
	while ('0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - '0');
	if (*str != '\0')
	{
		// printf("invalid 2\n");
		return (-1);
	}
	if (num < -2147483648 || num > 2147483647)
	{
		// printf("invalid 3\n");
		return (-1);
	}
	*result = sign * num;
	return (1);
}

t_list	*new_add_list(t_list *prev_node, int val)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	// printf("(new!)\n");
	new->num = val;
	new->index = 0;
	new->prev = prev_node;
	new->next = NULL;
	return (new);
}
