/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:05:59 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/22 08:26:53 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_info	vars;

	if (argc == 1)
		return (0); // 프롬프트 반환?
	setting(argc, &vars);
	if (parsing(argc, argv, &vars.a) == -1)
	{
		printf("Error\n");
		return (0);
	}
	indexing(&vars.a);
	pivot(argc - 1, &vars);
	hardcoding(&vars);
	greedy(&vars);
	last_sort(&vars);
	// system("leaks a.out");
	// ft_free(&a, &b); 만들기!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

// TODO 인자값 에러처리(정수x, 정수 이상, 중복) -> Error\n 출력하기
// TODO If no parameters are specified, the program must not display anything and give the prompt back.