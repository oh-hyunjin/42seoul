/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:05:59 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/19 10:30:58 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_sort(t_list *a)
{
	int		ra_num;
	t_node	*a_node;

	a_node = a->top;
	ra_num = 0;
	while (a_node != NULL)
	{
		if (a_node->index == 0)
			break ;
		a_node = a_node->next;
		ra_num++;
	}
	// printf("<%d, %d>\n", ra_num, a->len / 2);
	if (ra_num <= a->len / 2)
	{
		while (ra_num != 0)
		{
			ra(a);
			ra_num--;
		}
	}
	else
	{
		ra_num = a->len - ra_num;
		while (ra_num != 0)
		{
			rra(a);
			ra_num--;
		}
	}
	
}

int main(int argc, char *argv[])
{
	t_list	a;
	t_list	b;

	if (argc == 1)
		return (0); // 프롬프트 반환?
	setting(argc, &a, &b);
	if (parsing(argc, argv, &a) == -1)
	{
		printf("Error\n");
		return (0);
	}
	indexing(&a);
	pivot(argc - 1, &a, &b);
	hardcoding(&a);
	greedy(&a, &b);
	last_sort(&a);
	// test_print(&a, &b);
	// ft_free(&a, &b); 만들기!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

// TODO 5 4 3 2 1 0 넣어보기 -> 그냥 6개는 다 터짐..
// TODO 인자값 에러처리(정수x, 정수 이상, 중복) -> Error\n 출력하기
// TODO If no parameters are specified, the program must not display anything and give the prompt back.