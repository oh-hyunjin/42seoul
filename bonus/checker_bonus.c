/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:17:31 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/24 09:57:42 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_info *vars)
{
	t_node	*temp;

	if (vars->b.top != NULL)
		return (-1);
	temp = vars->a.top->next;
	while (temp != NULL)
	{
		if (temp->prev->num >= temp->num)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

int	end_checker(t_info *vars, int flag)
{
	if (flag == ERROR)
		ft_printf("Error\n");
	else if (flag == OK)
		ft_printf("OK\n");
	else if (flag == KO)
		ft_printf("KO\n");
	all_list_del(vars);
	system("leaks checker"); //지우기
	return (0);
}

int	ft_command(t_info *vars, char *command)
{
	if (ft_strncmp(command, "sa\n", ft_strlen(command)) == 0)
		swap(&vars->a);
	else if (ft_strncmp(command, "sb\n", ft_strlen(command)) == 0)
		swap(&vars->b);
	else if (ft_strncmp(command, "ss\n", ft_strlen(command)) == 0)
		ss(vars);
	else if (ft_strncmp(command, "pa\n", ft_strlen(command)) == 0)
		push(&vars->b, &vars->a);
	else if (ft_strncmp(command, "pb\n", ft_strlen(command)) == 0)
		push(&vars->a, &vars->b);
	else if (ft_strncmp(command, "ra\n", ft_strlen(command)) == 0)
		rotate(&vars->a);
	else if (ft_strncmp(command, "rb\n", ft_strlen(command)) == 0)
		rotate(&vars->b);
	else if (ft_strncmp(command, "rr\n", ft_strlen(command)) == 0)
		rr(vars);
	else if (ft_strncmp(command, "rra\n", ft_strlen(command)) == 0)
		r_rotate(&vars->a);
	else if (ft_strncmp(command, "rrb\n", ft_strlen(command)) == 0)
		r_rotate(&vars->b);
	else if (ft_strncmp(command, "rrr\n", ft_strlen(command)) == 0)
		rrr(vars);
	else
		return (-1);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_info	vars;
	char	*command;

	if (argc == 1)
		return (0);
	setting(&vars);
	if (parsing(argv, &vars.a) == -1)
		return (end_checker(&vars, ERROR));
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		if (ft_command(&vars, command) == -1)
		{
			free(command);
			return (end_checker(&vars, KO));
		}
		free(command);
	}
	if (is_sorted(&vars) == -1)
		return (end_checker(&vars, KO));
	return (end_checker(&vars, OK));
}
