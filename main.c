/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:49:11 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/09 12:32:32 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_checkprint(char c, unsigned int ptr)
{
	int fd;

	fd = 1;
	if (c == 'c')
		ft_putchar_fd(ptr, fd);
	//else if (c == 's')
		//ft_putstr_fd(ptr, fd);
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
	unsigned int	ptr;
	va_list			args;

	va_start (args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ptr = va_arg(args, unsigned int);
			ft_checkprint(format[i], ptr);
		}
		else
			ft_putchar_fd(format[i], 1);
	i++;
	}
	va_end(args);
	return (0);
}

int    main(void)
{
    ft_printf("%c", 'o');

    //ft_printf("%s", "Hello, World");
    //ft_printf("%p", *p);
    //ft_printf("%d", );
    //ft_print_f("%i", );
    //ft_printf("%u",);
    //ft_printf("%x", );
    //ft_printf("%X");
    //ft_printf("%%",)
}
