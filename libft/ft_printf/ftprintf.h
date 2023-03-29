/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:31:40 by francoma          #+#    #+#             */
/*   Updated: 2023/01/23 10:38:02 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stddef.h>
# include "../libft.h"

# define FLAGS "#0- +"
# define FLAGS_QTY 5
# define TYPES "cspdiuxX%"
# define DIGITS "0123456789abcdef"
# define NULL_STR "(null)"

typedef enum flags
{
	f_hash,
	f_zero,
	f_minus,
	f_space,
	f_plus,
}	t_e_flags;

typedef unsigned char	t_uchar;

typedef struct aconsumer
{
	t_uchar	flags[FLAGS_QTY];
	int		f_w;
	int		precision;
	char	type;
	int		is_negative_number;
}	t_aconsumer;

int		ft_min(int a, int b);
int		ft_max(int a, int b);
size_t	ft_pow(size_t n, size_t pow);
size_t	ft_abs(int n);

int		nth_in_str(char c, char *str);
int		in_str(char c, char *str);
int		ft_isupper(char c);
int		putstrn(char *s, int n);
int		putpadn(char pad, int n);

void	init_aconsumer(t_aconsumer *ac);
size_t	parse_aconsumer(const char *s, t_aconsumer *ac);
char	get_padder(t_aconsumer *ac);
int		get_base(t_aconsumer *ac);

int		is_int(char type);
int		is_unsigned_int(char type);
int		is_signed_int(char type);
int		is_hex(char type);

int		count_digits(size_t d, int base);

int		display_char(t_aconsumer *ac, char c);
int		display_str(t_aconsumer *ac, char *s);
int		display_percent(t_aconsumer *ac);
int		display_u_number(t_aconsumer *ac, size_t n);
int		display_number(t_aconsumer *ac, int d);
int		display_ptr(t_aconsumer *ac, size_t ptr);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		put_sign(t_aconsumer *ac);
int		put_hex_prefix(t_aconsumer *ac, size_t n);
int		put_numbern(size_t num, int num_n, size_t base, char type);

#endif