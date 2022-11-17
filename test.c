/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:03:04 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/17 10:21:09 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_print(t_list *a, t_list *b)
{
	t_node	*temp;

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

void	command_test(t_list *a, t_list *b)
{
	// test_print(a, b);

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