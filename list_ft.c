/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:03 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/11 14:57:01 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		printf("invalid 1\n");
		return (-1);
	}
	while ('0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - '0');
	if (*str != '\0')
	{
		printf("invalid 2\n");
		return (-1);
	}
	if (num < -2147483648 || num > 2147483647)
	{
		printf("invalid 3\n");
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
	printf("(new!)\n");
	new->num = val;
	new->index = 0;
	new->prev = prev_node;
	new->next = NULL;
	return (new);
}

void	test_print(t_vars *a, t_vars *b)
{
	t_list	*temp;

	printf("a : ");
	temp = a->top;
	while (temp != NULL)
	{
		printf("[%d:%d]", temp->num, temp->index);
		temp = temp->next;
	}
	if (a->top != NULL && a->btm != NULL)
		printf(" (%d, %d)", a->top->num, a->btm->num);
	printf("\nb : ");
	temp = b->top;
	while (temp != NULL)
	{
		printf("[%d:%d]", temp->num, temp->index);
		temp = temp->next;
	}
	if (b->top != NULL && b->btm != NULL)
		printf(" (%d, %d)", b->top->num, b->btm->num);
	printf("\n----------------------\n\n");
}

void	command_test(t_vars *a, t_vars *b)
{
	test_print(a, b);

	// swap(a);
	// test_print(a, b);

	// push(a, b);
	// test_print(a, b);

	// push(a, b);
	// test_print(a, b);

	// swap(a);
	// test_print(a, b);

	// push(a, b);
	// test_print(a, b);

	// rotate(a);
	// test_print(a, b);

	// push(a, b);
	// test_print(a, b);

	// rotate(a);
	// test_print(a, b);

	// rotate(b);
	// test_print(a, b);

	// r_rotate(b);
	// test_print(a, b);
}