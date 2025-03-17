/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:53:51 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/11 13:37:51 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isfound(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	finish;

	if (s1 == NULL || set == NULL || s1[0] == '\0')
		return (ft_strdup(""));
	i = 0;
	while (isfound(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1);
	if (i)
		i--;
	while (isfound(s1[i], set) && i)
		i--;
	finish = i;
	if (finish >= start && finish)
		finish = finish - start + 1;
	str = (char *)malloc((finish + 1) * (sizeof(char)));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1 + start, finish);
	str[finish] = '\0';
	return (str);
}
