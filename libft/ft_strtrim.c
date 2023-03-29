/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:22:12 by francoma          #+#    #+#             */
/*   Updated: 2023/01/10 15:20:46 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned char	in_set(char c, char const *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

static size_t	trimmed_strlen(char const *s, char const *set, size_t *begin)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (s[i] && in_set(s[i], set))
		i++;
	len = ft_strlen(s + i);
	while (len && in_set(s[i + len - 1], set))
		len--;
	*begin = i;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	begin;
	size_t	len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	len = trimmed_strlen(s1, set, &begin);
	s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	s2[len] = '\0';
	i = 0;
	while (i < len)
	{
		s2[i] = s1[begin + i];
		i++;
	}
	return (s2);
}
