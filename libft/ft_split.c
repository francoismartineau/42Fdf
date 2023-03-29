/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:53:41 by francoma          #+#    #+#             */
/*   Updated: 2023/01/25 10:40:52 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// O(3n)
//	.compte strs
//	.compte str lens
//	.copie

static void	free_strs(char **strs, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(strs[i++]);
	free(strs);
}

static int	count_strs(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static size_t	strlen_sep(char const *s, char sep)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != sep)
		len++;
	return (len);
}

static char	*strdup_sep(char const *s1, char sep, int *i)
{
	char	*s2;

	s2 = malloc(strlen_sep(s1, sep) + 1);
	if (!s2)
		return (NULL);
	*i = 0;
	while (s1[*i] && s1[*i] != sep)
	{
		s2[*i] = s1[*i];
		(*i)++;
	}
	s2[*i] = '\0';
	while (s1[*i] && s1[*i] == sep)
		(*i)++;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		incr;

	if (!s)
		return (NULL);
	strs = ft_calloc(count_strs(s, c) + 1, sizeof(*strs));
	if (!strs)
		return (NULL);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	j = 0;
	while (s[i])
	{
		strs[j] = strdup_sep(&s[i], c, &incr);
		if (!strs[j++])
		{
			free_strs(strs, j);
			return (NULL);
		}
		i += incr;
	}
	return (strs);
}
