/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:34:05 by francoma          #+#    #+#             */
/*   Updated: 2023/01/23 10:37:59 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_pow(size_t n, size_t pow)
{
	size_t	res;
	size_t	i;

	res = 1;
	i = 0;
	while (i < pow)
	{
		res *= n;
		i++;
	}
	return (res);
}

size_t	ft_abs(int n)
{
	if (n < 0)
		return (-(size_t)n);
	return (n);
}
