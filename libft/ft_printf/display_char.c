/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:26:52 by francoma          #+#    #+#             */
/*   Updated: 2023/01/23 10:37:59 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	display_char(t_aconsumer *ac, char c)
{
	char	padder;
	int		f_w;
	int		res;

	res = 0;
	f_w = ft_max(ac->f_w, 1);
	padder = get_padder(ac);
	if (ac->flags[f_minus])
		if (-1 == ft_putchar(c))
			return (-1);
	if (-1 == putpadn(padder, f_w - 1))
		return (-1);
	if (!ac->flags[f_minus])
		if (-1 == ft_putchar(c))
			return (-1);
	return (f_w);
}

int	display_percent(t_aconsumer *ac)
{
	return (display_char(ac, '%'));
}
