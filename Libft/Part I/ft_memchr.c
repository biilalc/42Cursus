/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@42Kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:00:00 by bcayir            #+#    #+#             */
/*   Updated: 2022/02/10 21:05:56 by bcayir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	a;

	if (!s && !n)
		return (0);
	str = (unsigned char *)s;
	i = 0;
	a = (unsigned char )c;
	while (i < n)
	{
		if (str[i] == a)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
