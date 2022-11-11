/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:47:44 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/11 15:04:13 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("cant find\n");
	return (top);
}

void	all_list_del(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(temp);
	}
}

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

	a->len = argc - 1;
	pivot1 = a->len / 3;
	pivot2 = a->len / 3 * 2;
	a->top = NULL; // 필요 없나?
	a->btm = NULL; // 이것도..
	b->top = NULL;
	b->btm = NULL;
}

void	under_pivot1()
{
	
}

void	under_pivot2()
{
	
}

int main(int argc, char *argv[])
{
	t_vars	a;
	t_vars	b;

	setting(argc, &a, &b);
	parsing(argc, argv, &a);
	indexing(&a);
	command_test(&a, &b);
	under_pivot1();
	under_pivot2();

	printf("\n");
}
