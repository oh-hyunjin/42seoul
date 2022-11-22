/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:37 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/22 08:02:50 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				len;
	struct s_node	*top;
	struct s_node	*btm;
}	t_list;

typedef struct s_node
{
	int				num;
	int				index;
	int				ra_num;
	int				rb_num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_info
{
	struct s_list	a;
	struct s_list	b;
}	t_info;

typedef struct s_rotateNum
{
	int	ra; // int형 맞나..
	int	rb;
}	t_rotateNum;

// main.c
void	last_sort(t_info *vars);

// push_swap.c
void	setting(int argc, t_info *vars);
int		parsing(int argc, char *argv[], t_list *a);
void	indexing(t_list *a);
void	pivot(int len, t_info *vars);
void	hardcoding(t_info *vars);

// instruction.c
void	sa(t_info *vars);
void	pa(t_info *vars);
void	pb(t_info *vars);
void	rr(t_info *vars);
void	rrr(t_info *vars);

// instruction2.c
void	ra(t_info *vars);
void	rb(t_info *vars);
void	rra(t_info *vars);
void	rrb(t_info *vars);

// instruction_utils.c
void	push(t_list *before, t_list *after);
void	rotate(t_list *vars);
void	r_rotate(t_list	*vars);

// greedy.c
void	greedy(t_info *vars);
void	get_min_instruction(t_info *vars, t_node **min);
int		is_min(t_node *b, t_node *min, t_rotateNum rotate_cnt, t_info vars);
void	rotate_before_push(t_info *vars, int ra_num, int rb_num);
void	rotate_together(t_info *vars, int *ra_num, int *rb_num);

// utils.c
void	all_list_del(t_node *var);
int		atoi_valid_check(char *str, int *result);
t_node	*new_add_list(t_node *prev_node, int val);
int		ft_abs(int num);

// test.c
void	test_print(t_list *a, t_list *b);
void	command_test(t_list *a, t_list *b);

#endif