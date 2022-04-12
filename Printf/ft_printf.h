/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@42Kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:34:40 by bcayir            #+#    #+#             */
/*   Updated: 2022/03/08 16:34:41 by bcayir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdio.h"
# include "unistd.h"
# include "stdarg.h"
# include "stdlib.h"

char	*ft_itoa(int n);
int		ft_printstr(char *s);
int		ft_printnbr(int n);
int		ft_putnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_putchar(char c);
int		ft_print_hex(unsigned int n, const char format);
int		ft_print_ptr(unsigned long long n);
int		ft_printf(const char *str, ...);
void	ft_putstr(char *s);
void	ft_put_hex(unsigned int n, const char format);

#endif
