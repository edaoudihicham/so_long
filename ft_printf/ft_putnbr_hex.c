/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:04:10 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/18 16:04:24 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n, int isupper)
{
	int		count;
	char	*base;

	if (isupper == 'x')
		base = "0123456789abcdef";
	else if (isupper == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_putnbr_hex(n / 16, isupper);
		count += ft_putnbr_hex(n % 16, isupper);
	}
	return (count);
}
