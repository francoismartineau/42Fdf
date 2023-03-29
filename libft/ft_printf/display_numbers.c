/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:51:44 by francoma          #+#    #+#             */
/*   Updated: 2023/01/23 10:37:59 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static int	_display_number(t_aconsumer *ac, size_t n, int num_n, int padn)
{
	char	padder;

	padder = get_padder(ac);
	if (!ac->flags[f_minus] && padder == ' ')
		if (-1 == putpadn(padder, padn))
			return (-1);
	if (-1 == put_sign(ac))
		return (-1);
	if (-1 == put_hex_prefix(ac, n))
		return (-1);
	if (!ac->flags[f_minus] && padder == '0')
		if (-1 == putpadn(padder, padn))
			return (-1);
	if (n || ac->precision)
		if (-1 == put_numbern(n, num_n, get_base(ac), ac->type))
			return (-1);
	if (ac->flags[f_minus])
		if (-1 == putpadn(padder, padn))
			return (-1);
	return (0);
}

int	display_u_number(t_aconsumer *ac, size_t n)
{
	char	prefix_n;
	int		num_n;
	int		count;

	prefix_n = 2 * (ac->type == 'p' || (ac->flags[f_hash] && n));
	num_n = ft_max(count_digits(n, get_base(ac)), ac->precision);
	num_n -= (!n && !ac->precision);
	count = ft_max(ac->f_w, prefix_n + num_n);
	if (-1 == _display_number(ac, n, num_n, count - prefix_n - num_n))
		return (-1);
	return (count);
}

int	display_number(t_aconsumer *ac, int n)
{
	int		sign;
	int		count;
	int		num_n;

	sign = 0;
	if (n < 0)
		ac->is_negative_number = 1;
	if (n < 0 || ac->flags[f_plus] || ac->flags[f_space])
		sign = 1;
	num_n = ft_max(count_digits(ft_abs(n), get_base(ac)), ac->precision);
	num_n -= (!n && !ac->precision);
	count = ft_max(ac->f_w, sign + num_n);
	if (-1 == _display_number(ac, ft_abs(n), num_n, count - sign - num_n))
		return (-1);
	return (count);
}

int	display_ptr(t_aconsumer *ac, size_t ptr)
{
	int		count;
	int		num_n;

	num_n = count_digits(ptr, 16);
	count = ft_max(ac->f_w, 2 + num_n);
	if (-1 == _display_number(ac, ptr, num_n, count - 2 - num_n))
		return (-1);
	return (count);
}
