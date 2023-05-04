/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:00:14 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/04 16:12:21 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void ft_putchar_fd(int s)
{
    write(1, &s, 1);
}

void ft_checktype(const char type, va_list args)
{
    int   c;

    if (type == 'c')
      ft_putchar_fd(args);
    else
        printf("%s", "nada");
    return;
}

int ft_printf(const char *format, ...)
{
    int i;

    i = 0;
    va_list args;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            ft_checktype(format[++i], va_arg(args, int));
            i++;
        }
        else
            ft_putchar_fd(format[i]);
    }

    va_end(args);
    return (0);
}

int main(void)
{
    char *farray = "o";

    ft_printf("%c", farray);
}
