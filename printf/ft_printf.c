/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:50:32 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/20 22:49:44 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkerror(int n)
{
	static int	error;

	if (n == 1)
		error = 1;
	if (n == 2)
		error = 0;
	return (error);
}

int	process_format(const char *frm, size_t *i, va_list args)
{
	int	count;

	count = 0;
	if (frm[*i] == 'd' || frm[*i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (frm[*i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (frm[*i] == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (frm[*i] == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (frm[*i] == 'x' || frm[*i] == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), frm[*i]);
	else if (frm[*i] == 'p')
		count += ft_putptr((unsigned long)va_arg(args, void *));
	else if (frm[*i] == '%')
		count += ft_putchar('%');
	else
		(*i)--;
	return (count);
}

int	ft_printf(const char *frm, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, frm);
	if (!frm)
		return (-1);
	checkerror(2);
	while (frm[i])
	{
		if (frm[i] == '%')
		{
			i++;
			count += process_format(frm, &i, args);
		}
		else
			count += ft_putchar(frm[i]);
		i++;
	}
	va_end(args);
	if (checkerror(0))
		return (-1);
	return (count);
}
