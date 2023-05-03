/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:00:14 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/03 19:54:18 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_checktype(int c, const char *s)
{
	if (c == 's')
		ft_putstr_fd(c, 1);
	else if (c == 'd')
		ft_putnbr_fd(c, 1);
	else if (c == 'c')
		ft_putchar_fd(c, 1);
	else if (c == 'p')
	else if (c == 'd')
	else if (c == 'i')
	else if (c == 'u')
	else if (c == 'x')
	else if (c == 'X')
	else
		'%'
}

void  ft_putchar_fd(int s)
{
    write(1, &s, 1);
}


void  ft_checktype(const char *format, va_list args)
{3
    int i;

    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
            i++;
        else if (format[i] == 'c')
        {
            char ch = va_arg(args, int);
            ft_putchar_fd(ch);
        }
        else if (format[i] == 's')
        {
            const char *s = va_arg(args, const char *)
        }
        else
            printf("%s", "nada");
        i++;
    }
    return ;
}

void    ft_printf(const char *format, ...)
{

    va_list args;
    va_start (args, format);
    ft_checktype(*format, args);
    va_end(args);
}

int    main(void)
{
    char    *farray = "o";

    ft_printf("%c", farray);
}

