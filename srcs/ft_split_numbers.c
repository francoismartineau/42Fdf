/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:41:58 by francoma          #+#    #+#             */
/*   Updated: 2023/02/06 13:40:08 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

size_t	count_numbers(char const *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || !ft_isdigit(s[i - 1])) && ft_isdigit(s[i]))
			count++;
		i++;
	}
	return (count);
}

void	split_numbers(int *dst, char const *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		while (src[i] && !ft_isdigit(src[i]))
			i++;
		if (!src[i])
			break ;
		dst[j] = ft_atoi(src + i - (i > 0 && src[i - 1] == '-'));
		dst[j] *= HEIGHT_PRECISION;
		while (ft_isdigit(src[i]))
			i++;
		j++;
	}
}
