/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:53:37 by francoma          #+#    #+#             */
/*   Updated: 2023/01/08 09:44:39 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned char	itoa_strlen(long n)
{
	unsigned char	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	_ft_itoa(long n, char **s_pos)
{
	if (n > 9)
		_ft_itoa(n / 10, s_pos);
	**s_pos = n % 10 + '0';
	(*s_pos)++;
}

char	*ft_itoa(int n)
{
	char			*s;
	char			*s_pos;
	long			l_n;

	l_n = n;
	s = malloc(itoa_strlen(l_n) + 1);
	if (!s)
		return (NULL);
	s_pos = s;
	if (l_n < 0)
	{
		*s_pos++ = '-';
		l_n = -l_n;
	}
	_ft_itoa(l_n, &s_pos);
	*s_pos = '\0';
	return (s);
}
