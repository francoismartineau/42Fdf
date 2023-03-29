/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:56:38 by root              #+#    #+#             */
/*   Updated: 2023/01/31 12:01:23 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_buff_mem_size(size_t req_size)
{
	size_t	size;

	size = 128;
	while (size < req_size)
		size *= 2;
	return (size);
}

char	*append_buff(char *buf, char *add)
{
	char	*res;
	size_t	buf_l;
	size_t	add_l;
	size_t	m_size;

	buf_l = ft_strlen(buf);
	add_l = ft_strlen(add);
	m_size = get_buff_mem_size(buf_l + add_l + 1);
	if (!buf || m_size != get_buff_mem_size(buf_l + 1))
	{
		res = malloc(sizeof(*res) * (m_size));
		if (!res)
		{
			free(buf);
			return (NULL);
		}
		ft_memmove(res, buf, buf_l);
		free(buf);
	}
	else
		res = buf;
	ft_memmove(res + buf_l, add, add_l);
	res[buf_l + add_l] = '\0';
	return (res);
}
