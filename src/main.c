/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:05:59 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/24 10:11:35 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_sort(t_info *vars)
{
	int		ra_num;
	int		reverse_flag;
	t_node	*a_node;

	a_node = vars->a.top;
	ra_num = 0;
	reverse_flag = 0;
	while (a_node != NULL)
	{
		if (a_node->index == 0)
			break ;
		a_node = a_node->next;
		ra_num++;
	}
	if (ra_num > vars->a.len / 2)
		reverse_flag = 1;
	while (vars->a.top->index != 0)
	{
		if (reverse_flag != 1)
			ra(vars);
		else
			rra(vars);
		ra_num--;
	}
}

int	free_split(char **split, int len)
{
	while (len >= 0)
		free(split[len--]);
	free(split);
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_info	vars;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	setting(&vars);
	if (parsing(argv, &vars.a) == -1)
	{
		ft_printf("Error\n");
		all_list_del(&vars);
		return (0);
	}
	if (vars.a.len == 1)
		return (0);
	indexing(&vars.a);
	pivot(vars.a.len, &vars);
	hardcoding(&vars);
	greedy(&vars);
	last_sort(&vars);
	all_list_del(&vars);
}
