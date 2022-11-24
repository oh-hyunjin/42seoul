/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:37 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/23 16:46:46 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define ERROR 0
# define OK 1
# define KO 2

# include <stdlib.h>
# include "../lib/src/libft/libft.h"
# include "../lib/src/get_next_line/get_next_line.h"
# include "../lib/src/ft_printf/ft_printf.h"

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

// checker_bonus.c (main)
int		ft_command(t_info *vars, char *command);
int		is_sorted(t_info *vars);
int		end_checker(t_info *vars, int flag);

// push_swap_bonus.c
void	setting(t_info *vars);
int		parsing(char *argv[], t_list *a);
int		free_split(char **split, int len);

// instruction_bonus.c
void	ss(t_info *vars);
void	rr(t_info *vars);
void	rrr(t_info *vars);

// instruction_utils_bonus.c
int		swap(t_list *vars);
int		push(t_list *before, t_list *after);
int		rotate(t_list *vars);
int		r_rotate(t_list	*vars);

// utils_bonus.c
void	all_list_del(t_info *vars);
int		atoi_valid_check(t_list *a, char *str, int *result);
int		new_add_list(t_list *a, int val);
int		duplicate_check(t_list *a, int num);

#endif