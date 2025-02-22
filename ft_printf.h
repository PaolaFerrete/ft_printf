/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:54:23 by pferrete          #+#    #+#             */
/*   Updated: 2023/05/16 14:38:47 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
void	ft_checkprint(char c, va_list arg, size_t *len);
void	ft_putchar(char c, size_t *len);
void	ft_puthex(unsigned int h, char c, size_t *len);
void	ft_putnbr(int n, size_t *len);
void	ft_putptr(size_t pointer, size_t *len);
void	ft_putstr(char *s, size_t *len);
void	ft_putunsig(unsigned int n, size_t *len);

#endif
