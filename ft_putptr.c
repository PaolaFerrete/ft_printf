/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:37:56 by paola             #+#    #+#             */
/*   Updated: 2023/05/15 18:23:24 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
