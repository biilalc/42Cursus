/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@42Kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:58:49 by bcayir            #+#    #+#             */
/*   Updated: 2022/05/21 23:58:53 by bcayir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char a);
void	ft_bzero(void *s, int n);

int		*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *s);
int		convert_decimal(int *array);
int		*convert_binary(int n);

#endif
