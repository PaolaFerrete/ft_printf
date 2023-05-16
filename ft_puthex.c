/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:57:55 by paola             #+#    #+#             */
/*   Updated: 2023/05/16 14:36:01 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
