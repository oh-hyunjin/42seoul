/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:47:44 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/24 09:58:22 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	free_split(char **split, int len)
{
	while (len >= 0)
		free(split[len--]);
	free(split);
	return (-1);
}

int	parsing(char *argv[], t_list *a)
{
	char	**split_ret;
	int		i;
	int		t;
	int		val;

	i = 0;
	while (argv[++i] != NULL)
	{
		split_ret = ft_split(argv[i], ' ');
		if (split_ret == NULL || *split_ret == NULL)
			return (-1);
		t = -1;
		while (split_ret[++t] != NULL)
		{
			if (atoi_valid_check(a, split_ret[t], &val) == -1 \
				|| new_add_list(a, val) == -1)
				return (free_split(split_ret, t));
			(a->len)++;
		}
		free_split(split_ret, t);
	}
	return (1);
}

void	setting(t_info *vars)
{
	vars->a.len = 0;
	vars->b.len = 0;
	vars->a.top = NULL;
	vars->a.btm = NULL;
	vars->b.top = NULL;
	vars->b.btm = NULL;
}
