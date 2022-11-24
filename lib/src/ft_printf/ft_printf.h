/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:48:08 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/23 15:28:32 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_info2
{
	int		flag[5];
	int		width;
	int		precision;
	char	specifier;
	int		len;
	int		pre;
	int		zero;
	int		blank;
}	t_info2;

// ft_printf.c
int		ft_printf(const char *fix, ...);
int		run(va_list ap, t_info2 info, long long *ret);
int		print_ptr(uintptr_t var, t_info2 info, long long *ret);
int		print_percent(t_info2 info, long long *ret);
int		get_blank_num(t_info2 info);

// option.c
void	flag_check(const char **fix, int flag[]);
void	width_check(va_list ap, const char **fix, t_info2 *info);
void	preci_check(va_list ap, const char **fix, t_info2 *info);
int		check(t_info2 *info, long long *ret);

// type.c
int		print_int(int var, t_info2 info, long long *ret);
int		print_uin(unsigned int var, t_info2 info, long long *ret);
int		print_hex(unsigned int var, t_info2 info, long long *ret);
int		print_cha(char var, t_info2 info, long long *ret);
int		print_str(char *var, t_info2 info, long long *ret);

// put.c
void	ft_putnbr(int len, long long num, long long *ret);
void	ft_putchar(char a, int num, t_info2 info, long long *ret);
void	ft_putsign(int var, t_info2 *info);
void	ft_putprefix(unsigned long var, t_info2 info);
void	ft_putnbr_base(unsigned long var, t_info2 info, long long *ret);

// getlen.c
int		intlen(t_info2 *info, long num);
int		uintlen(t_info2 *info, unsigned int num);
int		hexlen(t_info2 *info, unsigned long num);
int		ft_strlen3(t_info2 *info, void *var);
int		get_zero_num(t_info2 info);

#endif