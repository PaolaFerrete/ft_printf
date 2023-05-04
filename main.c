/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:49:11 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/04 19:20:55 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_putchar_fd(int s)
{
	write(1, &s, 1);
}

void	ft_checkprint(char c, int args)
{

	if (c == 'c')
		ft_putchar_fd(c);
	else if (c == 's')
		printf("%s", "string");
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
		ft_putchar_fd(c);
}

int	ft_checktype(int type)
{
	char	*str;
	int		i;

	str = "cspdiuxX";
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)type)
		{
			return (type);
		}
		i++;
	}
	return (0);

}


int	ft_printf(const char *format, ...)
{
	int				i;
	unsigned int	ptr;

	va_list	args;

	va_start (args, format);

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_checktype(format[i]) != 0)
			{
				ptr = va_arg(args, unsigned int);
				ft_checkprint(format[i], ptr);
			}
		}
		else
			ft_putchar_fd(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("OIeee %c", "D");

	//ft_printf("%s", "Hello, World");
	//ft_printf("%p", *p);
	//ft_printf("%d", );
	//ft_print_f("%i", );
	//ft_printf("%u",);
	//ft_printf("%x", );
	//ft_printf("%X");
	//ft_printf("%%",)
}
