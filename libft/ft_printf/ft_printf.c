/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:51:20 by francoma          #+#    #+#             */
/*   Updated: 2023/01/23 10:37:59 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftprintf.h"

static int	consume_a(t_aconsumer *ac, va_list ap)
{
	int	count;

	if (ac->type == 'c')
		count = display_char(ac, va_arg(ap, int));
	else if (ac->type == 's')
		count = display_str(ac, va_arg(ap, char *));
	else if (ac->type == 'p')
		count = display_ptr(ac, va_arg(ap, size_t));
	else if (is_signed_int(ac->type))
		count = display_number(ac, va_arg(ap, int));
	else if (is_unsigned_int(ac->type))
		count = display_u_number(ac, va_arg(ap, unsigned int));
	else if (ac->type == '%')
		count = display_percent(ac);
	else
		count = 0;
	return (count);
}

static int	_ft_printf(const char *format, va_list ap)
{
	t_aconsumer	ac;
	size_t		i;
	int			count;
	int			_count;

	count = 0;
	_count = 0;
	i = -1;
	while (format[++i] && _count != -1)
	{
		if (format[i] == '%' && format[i + 1])
		{
			i += parse_aconsumer(format + i, &ac);
			_count = consume_a(&ac, ap);
			count += _count;
		}
		else
		{
			_count = ft_putchar(format[i]);
			count++;
		}
	}
	if (_count == -1)
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	if (!format)
		return (0);
	va_start(ap, format);
	count = _ft_printf(format, ap);
	va_end(ap);
	return (count);
}
