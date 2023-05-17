/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:49:11 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/17 17:43:47 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

void	ft_putchar(char c, size_t *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *s, size_t *len)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", len);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
}

void	ft_putptr(size_t pointer, size_t *len)
{
	char	str[25];
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;

	if (pointer == 0)
		ft_putstr("(nil)", len);
	else
	{
		ft_putstr("0x", len);
		while (pointer != 0)
		{
			str[i] = hex[pointer % 16];
			pointer = pointer / 16;
			i++;
		}
		i -= 1;
		while (i >= 0)
			ft_putchar(str[i--], len);
	}
}
void	ft_putnbr(int n, size_t *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else if (n == 0)
		ft_putchar(n + 48, len);
	else if (n < 0)
	{
		ft_putchar('-', len);
		n *= -1;
		ft_putnbr(n, len);
	}
	else if (n < 10)
		ft_putchar(n + 48, len);
	else
	{
		ft_putnbr(n / 10, len);
		ft_putchar((char)(n % 10 + 48), len);
	}
}
void	ft_putunsig(unsigned int n, size_t *len)
{
	if (n < 10)
		ft_putchar(n + 48, len);
	else
	{
		ft_putunsig(n / 10, len);
		ft_putchar((char)(n % 10 + 48), len);
	}
}

void	ft_puthex(unsigned int h, char c, size_t *len)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (h >= 16)
	{
		ft_puthex(h / 16, c, len);
		ft_putchar((hex[h % 16]), len);
	}
	else if (h < 16)
		ft_putchar((hex[h % 16]), len);
}

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
	size_t			len;%%
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
		i++;%%
}

int	main(void)
{
	int	lenft = 0;
	int	lenprintf = 0;
/*

	ft_printf(" NULL %s NULL ", NULL);
	printf("\n");
*/


/*
	lenprintf = printf("\n");
	printf("%d\n", lenprintf);
	lenft = ft_printf("\n");
➜  ft_printf git:(master) ✗
	printf("%d\n", lenft);
*/
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


	printf("PRINTF ->\n");
	lenprintf = printf("%c", 'o');
	printf("\n");
	printf("O tamanho: %d\n", lenprintf);
	printf("FT_PRINTF ->\n");
	lenft = ft_printf("%c", 'o');
	printf("\n");
	printf("O tamanho: %d", lenft);
	printf("\n");


	printf("PRINTF -> || ");
	lenprintf = printf("%s", "Hello, World");
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%s", "Hello, World");
	ft_printf(" || %d", lenft);
	printf("\n\n");

*/
/*

	printf("PRINTF -> ||");
	lenprintf = printf("%ld", -2147483648);
	printf(" || %d", lenprintf);
	printf("\n");
	ft_printf("FT_PRINTF -> ||");
    lenft = ft_printf("%d", -2147483648);
	ft_printf("|| %d", lenft);
	printf("\n\n");
	printf("PRINTF -> ||");
	lenprintf = printf("%d", 2147483647);
	printf(" || %d", lenprintf);
	printf("\n");
	ft_printf("FT_PRINTF -> ||");
    lenft = ft_printf("%d", 2147483647);
	ft_printf("|| %d", lenft);
	printf("\n");
*/
/*

	printf("PRINTF -> ||");
	lenprintf = printf("%li", -2147483648);
	printf(" || %i\n", lenprintf);

	ft_printf("FT_PRINTF -> || ");
    lenft = ft_printf("%i", -2147483648);
	ft_printf(" || %i", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf = printf("%i", 2147483647);
	printf(" || %i\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
    lenft = ft_printf("%i", 2147483647);
	ft_printf("|| %i", lenft);
	printf("\n\n");
*/


/*
	printf("PRINTF -> || ");
	lenprintf = printf("%u", 25);
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> ||");
	lenft = ft_printf("%u", 25);
	ft_printf(" || %d", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf = printf("%u", -5);
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%u", -5);
	ft_printf(" || %d", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf = printf("%u", 0);
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%u", 0);
	ft_printf(" || %d", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf = printf("%lu", -2147483648);f (h >= 16)
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%u", -2147483648);
	ft_printf(" || %d", lenft);
	printf("\n\n");
*/

/*
	printf("PRINTF -> || ");
	lenprintf = printf("%x ", 48);
	lenprintf = printf("%X", 48);
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%x ", 48);
	lenft = ft_printf("%X", 48);
	ft_printf(" || %d", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf = printf("%x ", 0);
	lenprintf = printf("%X", 0);
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%x ", 0);
	lenft = ft_printf("%X", 0);
	ft_printf(" || %d", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf = printf("%x ", 'a');
	lenprintf = printf("%X", 'a');
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%x ", 'a');
	lenft = ft_printf("%X", 'a');
	ft_printf(" || %d", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf = printf("%x ", 'A');
	lenprintf = printf("%X", 'A');
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%x ", 'A');
	lenft = ft_printf("%X", 'A');
	ft_printf(" || %d", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf = printf("%x ", 'z');
	lenprintf = printf("%X", 'z');
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%x ", 'z');
	lenft = ft_printf("%X", 'z');
	ft_printf(" || %d", lenft);
	printf("\n\n");


	printf("\n");
	printf("%x\n", 127);
	ft_printf("%x", -25);
	printf("\n");
	printf("%x\n", -25);
*/
/*
	printf("PRINTF -> || ");
	lenprintf = printf("%%");
	printf(" || %d\n", lenprintf);
	ft_printf("FT_PRINTF -> || ");
	lenft = ft_printf("%%");
	ft_printf(" || %d", lenft);
	printf("\n\n");
*/


	void	*ptr = NULL;
	void	*p = "string";
	void	*t = "oioioi";

	printf("PRINTF -> || ");
	lenprintf =  printf("%p", ptr);
	printf("|| %d\n", lenprintf);
	ft_printf("FT_PRINTF -> ||");
	lenft = ft_printf("%p", ptr);
	ft_printf(" || %d", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf =  printf("%p", p);
	printf("|| %d\n", lenprintf);
	ft_printf("FT_PRINTF -> ||");
	lenft = ft_printf("%p", p);
	ft_printf(" || %d", lenft);
	printf("\n\n");

	printf("PRINTF -> || ");
	lenprintf =  printf("%p", t);
	printf("|| %d\n", lenprintf);
	ft_printf("FT_PRINTF -> ||");
	lenft = ft_printf("%p", t);
	ft_printf(" || %d", lenft);
	printf("\n\n");


}
