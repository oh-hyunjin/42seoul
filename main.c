/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:05:59 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/14 13:51:56 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_vars	a;
	t_vars	b;

	setting(argc, &a, &b);
	parsing(argc, argv, &a);
	indexing(&a);
	// test_print(&a, &b);
	pivot(argc - 1, &a, &b);
	hardcoding(&a);
	// test_print(&a, &b);

	greedy(&a, &b);
}
