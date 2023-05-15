/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:30:48 by paola             #+#    #+#             */
/*   Updated: 2023/05/15 18:22:04 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
