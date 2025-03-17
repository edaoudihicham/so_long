/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:48:28 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/11 14:52:40 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (srclen);
	destlen = ft_strlen(dst);
	j = destlen;
	if (dstsize == 0 || dstsize <= destlen)
		return (srclen + dstsize);
	while (src[i] != '\0' && i < dstsize - destlen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (destlen + srclen);
}
