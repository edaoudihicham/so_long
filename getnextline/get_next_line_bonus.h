/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaoudihicham <edaoudihicham@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:53:01 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/02/06 18:23:42 by edaoudihich      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strchrlen_gnl(char *s, int c);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*trim_leftovers(char *leftovers);
char	*read_to_leftovers(int fd, char *leftovers);
char	*get_next_line(int fd);
#endif
