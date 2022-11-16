/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:37 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/14 13:54:52 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_vars
{
	char			name;
	int				len;
	struct s_list	*top;
	struct s_list	*btm;
}	t_vars;

typedef struct s_list
{
	int				num;
	int				cnt;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;


// instruction.c
void	swap(t_vars *vars);
void	push(t_vars *before, t_vars *after);
void	rotate(t_vars *vars);
void	r_rotate(t_vars	*vars);

// push_swap.c
int		parsing(int argc, char *argv[], t_vars *a);
void	indexing(t_vars *a);
void	setting(int argc, t_vars *a, t_vars *b);
void	pivot(int len, t_vars *a, t_vars *b);
void	hardcoding(t_vars *a);

// greedy.c
void	count_num(t_vars *a, t_vars *b);
t_list *min_cnt(t_vars *a, t_vars *b);
void	put_target_top(t_vars *b, t_list *tar);
void	set_a_stack(t_vars *a, t_list *tar);

// utils.c
void	all_list_del(t_list *var);
int		atoi_valid_check(char *str, int *result);
t_list	*new_add_list(t_list *prev_node, int val);
t_list	*find_list(t_list *top, int num);

// test.c
void	test_print(t_vars *a, t_vars *b);
void	command_test(t_vars *a, t_vars *b);

#endif