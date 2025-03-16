/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:02:53 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/19 17:43:21 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += ft_putstr("(null)");
	}
	else
	{
		while (s[count])
		{
			ft_putchar(s[count]);
			count++;
		}
	}
	return (count);
}
