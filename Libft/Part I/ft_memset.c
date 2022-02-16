/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@42Kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:58:35 by bcayir            #+#    #+#             */
/*   Updated: 2022/02/10 16:27:45 by bcayir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*dizi;

	dizi = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		dizi[i] = c;
		i++;
	}
	b = dizi;
	return (b);
}
