/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:54:23 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/14 16:50:05 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

void	ft_putchar(char c, int fd);
int		ft_printf(const char *format, ...);
void	ft_checkprint(char c, va_list arg);
void	ft_putnbr(int n);
void	ft_putstr(char *s);

#endif




