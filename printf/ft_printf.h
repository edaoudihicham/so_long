/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:48:56 by hdaoudi           #+#    #+#             */
/*   Updated: 2024/11/19 17:33:21 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *frm, ...);
int	process_format(const char *frm, size_t *i, va_list args);
int	checkerror(int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr_hex(unsigned long nbr, int isUpper);
int	ft_putptr(unsigned long n);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
#endif
