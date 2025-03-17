/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:29:05 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/17 23:29:35 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;

		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	return (srclen);
}
