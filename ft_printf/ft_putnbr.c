/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:05:17 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/18 17:37:32 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len += ft_putstr("-2147483648");
	else if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
		len += ft_putnbr(n);
	}
	else if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
		len += ft_putchar(n + '0');
	return (len);
}
