/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:08:37 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/14 15:11:25 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_instruction_num(t_vars *a, t_vars *b)
{
	int		i;
	int		ra_cnt;
	int		rb_cnt;
	t_list	*a_temp;
	t_list	*b_temp;

	i = -1;
	b_temp = b->top;
	while(++i < b->len)
	{
		ra_cnt = 0;
		rb_cnt = i;
		if (i > b->len / 2)
			rb_cnt = b->len - i;
		if (a->top->index < b_temp->index) // ra 해야되는 경우
		{
			a_temp = a->top;
			while (a_temp->index < b_temp->index)
			{
				ra_cnt++;
				a_temp = a_temp->next;
			}
		}
		b_temp->cnt = ra_cnt + rb_cnt + 1;
		b_temp = b_temp->next;
	}
}

t_list	*min_instruction_num(t_vars *a, t_vars *b)
{
	t_list	*temp;
	t_list	*min;

	temp = b->top;
	min = temp;
	while (temp != NULL)
	{
		if (temp->cnt < min->cnt)
			min = temp;
		temp = temp->next;
	}
	printf("min cnt : (%d, %d)\n", min->num, min->cnt);
	return (min);
}

void	put_target_top(t_vars *b, t_list *tar)
{
	int		i;
	t_list	*temp;

	temp = b->top;
	i = 0; // 몇 번째에 있는지 -> ra or rra 결정
	while (temp != tar)
	{
		i++;
		temp = temp->next;
	}
	if (i < b->len / 2) // rotate b
		while (!i--)
			rotate(b);
	else // reverse rotate b
	{
		i = b->len - i;
		while (!i--)
			r_rotate(b);
	}
}

void	set_a_stack(t_vars *a, t_list *tar)
{
	if (tar->index < a->top)
		return ;
	while ()
}

void	greedy(t_vars *a, t_vars *b)
{
	t_list	*target;

	while (b->len != 0)
	{
		count_instruction_num(&a, &b);
		target = min_instruction_num(&a, &b); // 가장 적은 명령 수 찾기 = target
		put_target_top(&b, target); // rb or rrb로 target노드를 위로 올리기
		set_a_stack(&a, target); // target노드를 push할 위치를 만들기
		push(&b, &a);
	}
}
