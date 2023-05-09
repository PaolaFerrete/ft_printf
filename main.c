/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:49:11 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/09 14:16:51 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}


void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n == 0)
		ft_putchar(n + 48);
	else if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		ft_putnbr(n);
	}
	else if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((char)(n % 10 + 48));
	}
}

void	ft_checkprint(char c, va_list arg)
{
	int	fd;

	fd = 1;
	if (c == 'c')
		ft_putchar(va_arg(arg, int));
	else if (c == 's')
		ft_putstr(va_arg(arg, char *));
	else if (c == 'd')
		printf("%s", "int");
	else if (c == 'p')
		printf("%s", "pointer");
	else if (c == 'i')
		printf("%s", "integer base 10");
	else if (c == 'u')
		printf("%s", "unsigned decimal");
	else if (c == 'x')
		printf("%s", "hexadecimal lowercase");
	else if (c == 'X')
		printf("%s", "hexadecimal uppercase");
	else if (c == '%')
		printf("%s", "bla");
}

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

int	main(void)
{
	ft_printf("Oioioi");
	ft_printf("%c", 'o');
	ft_printf("%s", "Hello, World");
    //ft_printf("%p", *p);
    //ft_printf("%d", );
    //ft_print_f("%i", );
    //ft_printf("%u",);
    //ft_printf("%x", );
    //ft_printf("%X");
    //ft_printf("%%",)
}
