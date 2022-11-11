/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:37 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/11 14:39:40 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_vars
{
	int				len;
	struct s_list	*top;
	struct s_list	*btm;
}	t_vars;

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int		atoi_valid_check(char *str, int *result);
t_list	*new_add_list(t_list *prev_node, int val);
void	test_print(t_vars *a, t_vars *b);
void	command_test(t_vars *a, t_vars *b);
void	all_list_del(t_list *var);

void	change(t_list **a_top, t_list *a, t_list *b);
t_list	*find_list(t_list *top, int num);

void	swap(t_vars *vars);
void	push(t_vars *before, t_vars *after);
void	rotate(t_vars *vars);
void	r_rotate(t_vars	*vars);

#endif