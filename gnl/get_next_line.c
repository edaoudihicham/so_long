/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:53:11 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/20 00:53:51 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen_gnl(s1);
	if (s2)
		len2 = ft_strlen_gnl(s2);
	str = (char *)malloc((len1 + len2 + 1) * (sizeof(char)));
	if (str == NULL)
		return (free(s1), s1 = NULL, NULL);
	ft_memcpy_gnl(str, s1, len1);
	ft_memcpy_gnl(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;

	if (s == NULL || start > ft_strlen_gnl(s))
		return (free((char *)s), s = NULL, ft_strdup_gnl(""));
	slen = ft_strlen_gnl(&s[start]);
	if (slen < len)
		len = slen;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy_gnl(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}

char	*trim_leftovers(char **static_var)
{
	char	*new_leftovers;
	size_t	newline_position;
	char	*leftovers;

	leftovers = *static_var;
	new_leftovers = NULL;
	if (leftovers == NULL)
		return (free(leftovers), *static_var = NULL, NULL);
	newline_position = ft_strchrlen_gnl(leftovers, '\n');
	if (ft_strchr_gnl(leftovers, '\n'))
	{
		new_leftovers = ft_substr_gnl(leftovers, newline_position + 1,
				ft_strlen_gnl(leftovers) - (newline_position + 1));
		if (new_leftovers == NULL)
			return (free(leftovers), *static_var = NULL, NULL);
		free(leftovers);
		*static_var = NULL;
		return (new_leftovers);
	}
	return (free(leftovers), *static_var = NULL, NULL);
}

char	*read_to_leftovers(int fd, char *leftovers)
{
	char	*buffer;
	ssize_t	b_read;

	buffer = malloc((size_t)BUFFER_SIZE + 1 * sizeof(char));
	if (buffer == NULL)
		return (free(leftovers), NULL);
	b_read = 1;
	while (b_read > 0 && (!leftovers || ft_strchr_gnl(leftovers, '\n') == NULL))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
			return (free(buffer), free(leftovers), NULL);
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		leftovers = ft_strjoin_gnl(leftovers, buffer);
		if (leftovers == NULL)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(leftovers), leftovers = NULL, NULL);
	leftovers = read_to_leftovers(fd, leftovers);
	if (leftovers == NULL || leftovers[0] == '\0')
		return (free(leftovers), leftovers = NULL, NULL);
	if (ft_strchr_gnl(leftovers, '\n'))
		line = ft_substr_gnl(leftovers, 0, ft_strchrlen_gnl(leftovers, '\n')
				+ 1);
	else
		line = ft_strdup_gnl(leftovers);
	if (line == NULL)
		return (free(leftovers), leftovers = NULL, NULL);
	leftovers = trim_leftovers(&leftovers);
	return (line);
}
