/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:03:39 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/19 22:20:56 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	temp;

	temp = 0;
	if (checkerror(0) == 0)
		temp = write(1, &c, 1);
	if (temp == -1)
		checkerror(1);
	return (1);
}
