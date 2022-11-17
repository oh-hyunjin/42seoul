/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:05:59 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/17 10:42:51 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list	a;
	t_list	b;

	setting(argc, &a, &b);
	parsing(argc, argv, &a);
	indexing(&a);
	printf("indexed\n");
	test_print(&a, &b);
	pivot(argc - 1, &a, &b);
	hardcoding(&a);
	printf("hardcoded\n");
	test_print(&a, &b);

	greedy(&a, &b);
	test_print(&a, &b);
}

// TODO 5 4 3 2 1 0 넣어보기 -> 그냥 6개는 다 터짐..