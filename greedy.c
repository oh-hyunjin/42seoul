/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:08:37 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/17 12:06:46 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	return (-num);
}

// TODO ra나 rb가 a->len의 절반이나 b->len의 절반을 넘으면 -로 바꿔서 reverse임을 나타내기....
//		-> 그럼 min_cnt 비교해서 구할 때 절대값으로/..............
void	get_min_instruction(t_list	*a_lst, t_list *b_lst, t_node *min)
{
	t_node	*a;
	t_node	*b;
	int		ra_num; // int형 맞나..
	int		rb_num;
	int		del;

	b = b_lst->top;
	if (b->index == 1)
			del = 1;
	rb_num = 0;
	while(b != NULL) // < get rb >
	{
		a = a_lst->top;
		ra_num = 0;
		while (a != NULL) // < get ra > // ra_num == a->len 이면 ra_num = 0....
		{
			if (a->next == NULL)
			{
				ra_num = 0;
				break ;// 맞나..
			}
			if (a->index < b->index && b->index < a->next->index \
			 		|| b->index < a->next->index && a->next->index < a->index)
			{
				ra_num++;
				break ;
			}
			a = a->next;
			ra_num++;
		}
		b->ra_num = ra_num;
		if (ra_num > a_lst->len / 2)
			b->ra_num = ra_num - a_lst->len;
		b->rb_num = rb_num;
		if (rb_num > b_lst->len / 2)
			b->rb_num = rb_num - b_lst->len;
		if (ft_abs(b->ra_num) + ft_abs(b->rb_num) < min->ra_num + min->rb_num)
			min = b;
		printf("(%d, %d+%d) ", b->index, b->rb_num, b->ra_num);
		b = b->next;
		rb_num++;
	}
	printf("<min: %d>", min->index);
	printf("\n");
}

// struct cnt : ra_num, rb_num 하나 만들까..

void	rotateStack_beforePush(t_list *stack, int num)
{
	while (num > 0)
	{
		rotate(stack);
		num--;
	}
	while (num < 0)
	{
		r_rotate(stack);
		num++; 
	}
}

void	greedy(t_list *a, t_list *b)
{
	t_node	*target;

	while (b->len != 0)
	{
		target = b->top;
		get_min_instruction(a, b, target); // 가장 적은 명령 수 찾기 = target
		rotateStack_beforePush(b, target->rb_num); // rb or rrb로 target노드를 위로 올리기
		rotateStack_beforePush(a, target->ra_num); // target노드를 push할 위치를 만들기
		push(b, a);
	}
}
