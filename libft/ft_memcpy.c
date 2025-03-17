/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:40:14 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/12 22:00:46 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dst == src || n == 0)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (n != 0)
	{
		while (n--)
			*d++ = *s++;
	}
	return (dst);
}
