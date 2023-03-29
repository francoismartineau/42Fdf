/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:44:39 by francoma          #+#    #+#             */
/*   Updated: 2023/01/23 10:37:59 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftprintf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (s[i] && err != -1)
		err = ft_putchar(s[i++]);
	if (err == -1)
		return (-1);
	return (i);
}

int	put_sign(t_aconsumer *ac)
{
	int	res;

	res = 0;
	if (!is_signed_int(ac->type))
		return (res);
	if (ac->is_negative_number)
		res = ft_putchar('-');
	else if (ac->flags[f_plus])
		res = ft_putchar('+');
	else if (ac->flags[f_space])
		res = ft_putchar(' ');
	return (res);
}

int	put_hex_prefix(t_aconsumer *ac, size_t n)
{
	char	*prefix;

	if (!is_hex(ac->type) || (ac->type != 'p' && !n)
		|| (ac->type != 'p' && !ac->flags[f_hash]))
		return (0);
	if (ac->type == 'X' && ac->flags[f_hash])
		prefix = "0X";
	else
		prefix = "0x";
	return (ft_putstr(prefix));
}

int	put_numbern(size_t n, int num_n, size_t base, char type)
{
	char	*digits;
	char	dgt;
	int		i;
	int		dgt_count;
	int		err;

	err = 0;
	dgt_count = count_digits(n, base);
	i = num_n;
	while (--i >= dgt_count && err != -1)
		err = ft_putchar('0');
	digits = DIGITS;
	while (i >= 0 && err != -1)
	{
		dgt = digits[n / ft_pow(base, i) % base];
		if (ft_isupper(type))
			dgt = ft_toupper(dgt);
		err = ft_putchar(dgt);
		i--;
	}
	if (err == -1)
		return (-1);
	return (num_n);
}
