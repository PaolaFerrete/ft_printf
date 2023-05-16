/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:00:14 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/16 14:35:50 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkprint(char c, va_list arg, size_t *len)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (c == 'p')
		ft_putptr(va_arg(arg, size_t), len);
	else if (c == 'u')
		ft_putunsig(va_arg(arg, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(arg, unsigned int), c, len);
	else if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	size_t			len;
	va_list			args;

	va_start (args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_checkprint(format[++i], args, &len);
		else
			ft_putchar((char)(format[i]), &len);
		i++;
	}
	va_end(args);
	return (len);
}
