/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:20:09 by francoma          #+#    #+#             */
/*   Updated: 2023/02/04 15:19:58 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_minst(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	res_len;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t) start > ft_strlen(s))
		res_len = 0;
	else
		res_len = ft_minst(len, ft_strlen(&s[start]));
	res = malloc(res_len + 1);
	if (!res)
		return (NULL);
	res[res_len] = '\0';
	i = res_len;
	while (i--)
		res[i] = s[start + i];
	return (res);
}
