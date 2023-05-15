/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:16:33 by paola             #+#    #+#             */
/*   Updated: 2023/05/15 18:22:34 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
