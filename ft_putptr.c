/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:37:56 by paola             #+#    #+#             */
/*   Updated: 2023/05/14 16:52:00 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putptr(size_t pointer)
{
	char	str[25];
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;

	if (pointer == 0)
		ft_putstr("(nil)");
	else
	{
		ft_putstr("0x");
		while (pointer != 0)
		{
			str[i] = hex[pointer % 16];
			pointer = pointer / 16;
			i++;
		}
		i -= 1;
		while (i >= 0)
			ft_putchar(str[i--]);
	}
}
