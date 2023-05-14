/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:49:11 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/14 18:33:40 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libftprintf.h"

void	ft_putchar(char c, size_t *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *s, size_t *len)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
}

void	ft_checkprint(char c, va_list arg, size_t *len)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), len);
	//else if (c == 'd' || c == 'i')
		//ft_putnbr(va_arg(arg, int));
	//else if (c == 'p')
		//ft_putptr(va_arg(arg, size_t));
	//else if (c == 'u')
		//ft_putunsig(va_arg(arg, unsigned int));
	//else if (c == 'x' || c == 'x')
		//ft_puthex(va_arg(arg, unsigned int));
//	else if (c == '%')
	//	ft_putchar('%', len);
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

int	main(void)
{
	int	lenft;
	int	lenprintf;

/*
	printf("PRINTF ->\n");
	lenprintf = printf("Oioioi");
	printf("\n");
	printf("O tamanho: %d\n", lenprintf);
	printf("FT_PRINTF ->\n");
	lenft = ft_printf("Oioioi");
	printf("\n");
	printf("O tamanho: %d", lenft);
	printf("\n");
*/
/*
	printf("PRINTF ->\n");
	lenprintf = printf("%c", 'o');
	printf("\n");
	printf("O tamanho: %d\n", lenprintf);
	printf("FT_PRINTF ->\n");
	lenft = ft_printf("%c", 'o');
	printf("\n");
	printf("O tamanho: %d", lenft);
	printf("\n");
*/
	printf("PRINTF ->");
	lenprintf = printf("|| %s", "Hello, World");
	printf(" || %d\n", lenprintf);
	printf("FT_PRINTF ->");
	lenft = ft_printf("|| %s", "Hello, World");
	printf(" || %d\n", lenft);


    //ft_printf("%d", -2147483648);
	//printf("\n");
	//printf("%i", 25894);
	//printf("\n");
    //ft_print_f("%i", );
    //ft_printf("%u", 25);
	//printf("\n");
	//printf("%u", 25);
	//printf("\n");
	//ft_printf("%u", -5);
	//printf("\n");
	//printf("%u", -5);
	//printf("\n");
	//ft_printf("%u", 0);
	//printf("\n");
	//printf("%u", 0);
	//printf("\n");
	//ft_printf("%u", 2147483647);
	//printf("\n");
	//printf("%u", 2147483647);
	//printf("\n");
	/*
	ft_printf("%x", 48);
	printf("\n");
	printf("%x\n", 48);
	ft_printf("%x", 0);
	printf("\n");
	printf("%x\n", 0);
	ft_printf("%x", 'a');
	printf("\n");
	printf("%x\n", 'a');
	ft_printf("%x", 'A');
	printf("\n");
	printf("%x\n", 'A');
	ft_printf("%x", 127);
	printf("\n");
	printf("%x\n", 127);
	ft_printf("%x", -25);
	printf("\n");
	printf("%x\n", -25);
	*/
	/*
    ft_printf("%%");
	printf("\n");
	printf("%%\n");
	*/
	/*
	void	*ptr = NULL;
	void	*p = "string";
	void	*t = "oioioi";
	ft_printf("%p", ptr);
	printf("\n");
	printf("%p\n", ptr);
	ft_printf("%p", t);
	printf("\n");
	printf("%p\n", t);
	ft_printf("%p", p);
	printf("\n");
	printf("%p\n", p);
*/
}
