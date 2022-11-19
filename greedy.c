/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:08:37 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/19 13:04:26 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotateStack_beforePush(t_list *a, t_list *b, t_node *min)
{
	if (min->ra_num > 0 && min->rb_num > 0)
	{
		while (min->ra_num != 0 && min->rb_num != 0)
		{
			rr(a, b);
			min->ra_num--;
			min->rb_num--;
		}
	}
	else if (min->ra_num < 0 && min->rb_num < 0)
	{
		while (min->ra_num != 0 && min->rb_num != 0)
		{
			rrr(a, b);
			min->ra_num++;
			min->rb_num++;
		}
	}
	while (min->ra_num != 0)
	{
		if (min->ra_num > 0)
		{
			ra(a);
			min->ra_num--;
		}
		else
		{
			rra(a);
			min->ra_num++;
		}
	}
	while (min->rb_num != 0)
	{
		if (min->rb_num > 0)
		{
			rb(b);
			min->rb_num--;
		}
		else
		{
			rrb(b);
			min->rb_num++;
		}
	}
}

int	isMin(t_node *b, t_node *min, t_rotateNum rotateCnt, int alen, int blen)
{
	b->ra_num = rotateCnt.ra;
	b->rb_num = rotateCnt.rb;
	if (rotateCnt.ra > alen / 2) // 과반이면 ra보다 rra가 빠르다
		b->ra_num = rotateCnt.ra - alen; // reverse는 -로 처리
	if (rotateCnt.rb > blen / 2)
		b->rb_num = rotateCnt.rb - blen;
	if ((ft_abs(b->ra_num) + ft_abs(b->rb_num)) \
			< (ft_abs(min->ra_num) + ft_abs(min->rb_num)))
		return (1);
	return (0);
}

void	get_min_instruction(t_list	*a_lst, t_list *b_lst, t_node **min)
{ //min을 이중포인터로 받아야 하는 이유..
	t_node		*a;
	t_node		*b;
	t_rotateNum	rotateCnt;

	b = b_lst->top;
	rotateCnt.rb = 0;
	while(b != NULL) // < get rb >
	{
		a = a_lst->top;
		rotateCnt.ra = 1;
		while (a->next != NULL) // < get ra > // prev를 다루면??
		{
			if (a->index < b->index && b->index < a->next->index \
			|| b->index < a->next->index && a->next->index < a->index \
			|| a->next->index < a->index && a->index < b->index)
				break ;
			a = a->next;
			rotateCnt.ra++;
		}
		if (isMin(b, *min, rotateCnt, a_lst->len, b_lst->len))
			*min = b;
		b = b->next;
		rotateCnt.rb++;
	}
}

void	greedy(t_list *a_lst, t_list *b_lst)
{
	t_node	*min;

	while (b_lst->len != 0)
	{
		min = b_lst->top;
		min->ra_num = 0;
		min->rb_num = 0;
		get_min_instruction(a_lst, b_lst, &min); // 가장 적은 명령 수 찾기
		rotateStack_beforePush(a_lst, b_lst, min);
		pa(b_lst, a_lst);
		// test_print(a_lst, b_lst);
	}
}




// TODO: min값 변경은 되는데 변경된대로 rra 변경이 안됨
// (12 8 4 9 2 10 7 5 3 0 6 1 11) -> [5 6 8 9 10 11 12], [7 4 2 3 0 1]에서
	//min값은 7->4로 변경이 됐는데.. get_min_instruction -> greedy 과정에서 다시 초기화
		//돼서 min=b_lst->top으로 돌아감!!!!!!!!!

// rr처리 전 : 100->554~6nn, 500->4500 
// rr 처리 해서 확인하기

// built-in, origin, changed 
// <100> 573, 613, 583
// <500> 5227, 4570, 4270