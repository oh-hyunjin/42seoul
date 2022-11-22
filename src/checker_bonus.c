/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:17:31 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/23 08:19:02 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// bonus 폴더 만들어야 되는지..

int main()
{
	char	*command;
	t_info	vars;

	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		printf("%s<", command);
		if (command == "sa")
			sa(&vars);
		else if (command == "sb")
			sb(&vars);
		else if (command == "ss")
		{
			swap
		}
		else if (command == "pa")
			push(&vars.b, &vars.a);
		else if (command == "pb")
			push(&vars.a, &vars.b);
		else if (command == "ra")
			ra(&vars);
		else if (command == "rb")
			rb(&vars);
		else if (command == "rr")
		{
			rotate(&vars.a);
			rotate(&vars.b);
		}
		else if (command == "rra")
			rra(&vars);
		else if (command == "rrb")
			rrb(&vars);
		else if (command == "rrr")
		{
			r_rotate(&vars.a);
			r_rotate(&vars.b);
		}
	}
	if (is_sorted(a) == 1)
		printf("OK");
	else
		printf("KO");
}