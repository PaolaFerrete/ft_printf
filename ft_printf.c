/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:00:14 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/14 12:31:18 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int				i;
	va_list			args;

	va_start (args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_checkprint(format[++i], args);
		else
			ft_putchar(format[i++]);
	}
	va_end(args);
	return (0);
}
