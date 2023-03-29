/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:39:01 by francoma          #+#    #+#             */
/*   Updated: 2023/01/23 10:37:59 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	nth_in_str(char c, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	in_str(char c, char *str)
{
	return (nth_in_str(c, str) != -1);
}

int	ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	putstrn(char *s, int n)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (i < n && err != -1)
		err = ft_putchar(s[i++]);
	if (err == -1)
		return (-1);
	return (i);
}

int	putpadn(char pad, int n)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (i < n && err != -1)
	{
		err = ft_putchar(pad);
		i++;
	}
	if (err == -1)
		return (-1);
	return (i);
}
