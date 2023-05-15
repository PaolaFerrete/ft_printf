/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:41:22 by paola             #+#    #+#             */
/*   Updated: 2023/05/15 18:23:55 by pferrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *s, size_t *len)
{
	int	i;

	if (!s)
		ft_putstr("(nil)", len);
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
}
