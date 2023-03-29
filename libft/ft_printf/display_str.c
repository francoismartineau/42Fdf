/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:27:26 by francoma          #+#    #+#             */
/*   Updated: 2023/01/23 10:37:59 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	display_str(t_aconsumer *ac, char *s)
{
	char	padder;
	int		f_w;
	int		n;
	int		res;

	res = 0;
	if (!s)
		return (display_str(ac, NULL_STR));
	padder = get_padder(ac);
	n = ft_strlen(s);
	if (ac->precision != -1)
		n = ft_min(n, ac->precision);
	f_w = ft_max(ac->f_w, n);
	if (ac->flags[f_minus])
		res = putstrn(s, n);
	if (res < 0)
		return (res);
	res = putpadn(padder, f_w - n);
	if (res < 0)
		return (res);
	if (!ac->flags[f_minus])
		res = putstrn(s, n);
	if (res < 0)
		return (res);
	return (f_w);
}
