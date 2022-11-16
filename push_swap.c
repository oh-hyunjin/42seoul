/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:47:44 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/16 09:51:20 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char *argv[], t_vars *a)
{
	t_list	*temp;
	int		i;
	int		val;

	if (atoi_valid_check(argv[1], &val) == -1)
		return(-1);
	a->top = new_add_list(NULL, val);
	if (a->top == NULL)
		return (-1);
	temp = a->top;
	i = 1;
	while (++i < argc)
	{
		if (atoi_valid_check(argv[i], &val) == -1)
			return (-1);
		temp->next = new_add_list(temp, val);
		if (temp->next == NULL)
		{
			all_list_del(a->top);
			return (-1);
		}
		temp = temp->next;
	}
	a->btm = temp;
	return (1);
}

void	indexing(t_vars *a)
{
	int		idx;
	int		max_num;
	t_list	*max_node;
	t_list	*temp;

	idx = a->len - 1;
	while (idx >= 0)
	{
		temp = a->top;
		max_num = -100;
		while (temp != NULL)
		{
			if (temp->num > max_num && temp->index == 0)
			{
				max_node = temp;
				max_num = max_node->num;
			}
			temp = temp->next;
		}
		max_node->index = idx;
		idx--;
	}
}

void	setting(int argc, t_vars *a, t_vars *b)
{
	int	pivot1;
	int	pivot2;

	a->name = 'a';
	b->name = 'b';
	a->len = argc - 1;
	b->len = 0;
	pivot1 = a->len / 3;
	pivot2 = a->len / 3 * 2;
	a->top = NULL; // 필요 없나?
	a->btm = NULL; // 이것도..
	b->top = NULL;
	b->btm = NULL;
}

void	pivot(int len, t_vars *a, t_vars *b)
{
	int		pivot_1;
	int		pivot_2;
	t_list	*temp;

	pivot_1 = len / 3 * 2;	// 66
	pivot_2 = len / 3;		// 33
	// printf("pivot = %d, %d\n\n", pivot_1, pivot_2);
	while (len-- > 0)
	{
		temp = a->top;
		if (temp->num < pivot_1)
		{
			push(a, b);
			if (temp->num < pivot_2)
				rotate(b);
		}
		
		else
			rotate(a);
	}
	while (a->len > 3)
		push(a, b);
}

void	hardcoding(t_vars *a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	// printf("hardcoding!!\n");
	while (1)
	{
		first = a->top->num;
		second = first->next->num;
		third = second->next->num;
		if (first < second && second < third)
			break ;
		else if (first > second && first > third)
			rotate(a);
		else if (second > first && second > third)
			r_rotate(a);
		else if (third > first && third > second)
			swap(a);
	}
}
