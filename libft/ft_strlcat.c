/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:39:15 by francoma          #+#    #+#             */
/*   Updated: 2023/02/04 15:18:41 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

static size_t	ft_minst(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

	// if ((len1 / 2 + len2 / 2) > SIZE_MAX / 2)
	// 	return (0);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;	
	size_t	i;
	size_t	j;
	size_t	expected_len;

	if (!dst || !src)
		return (0);
	len1 = ft_minst(size, ft_strlen(dst));
	len2 = ft_strlen(src);
	expected_len = len1 + len2;
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && (i + 1 < size))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (expected_len);
}
