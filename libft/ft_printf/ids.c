/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ids.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:08:42 by francoma          #+#    #+#             */
/*   Updated: 2023/01/23 10:37:59 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	is_int(char type)
{
	return (type == 'd' || type == 'i' || type == 'u' || is_hex(type));
}

int	is_unsigned_int(char type)
{
	return (type == 'u' || type == 'x' || type == 'X');
}

int	is_signed_int(char type)
{
	return (type == 'd' || type == 'i');
}

int	is_hex(char type)
{
	return (type == 'x' || type == 'X' || type == 'p');
}
