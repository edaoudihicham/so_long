/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:44:02 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/11 15:52:48 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	slen(int n)
{
	long	i;
	long	nbr;

	nbr = n;
	i = 0;
	if (nbr == 0)
		nbr = 1;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		i += 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	if (n == 0)
		return (ft_strdup("0"));
	len = slen(n);
	nbr = n;
	str = malloc(sizeof(char) * ((len + 1)));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr)
	{
		str[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
