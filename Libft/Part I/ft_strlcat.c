/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@42Kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:34:16 by bcayir            #+#    #+#             */
/*   Updated: 2022/02/13 15:34:24 by bcayir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;
	size_t	srcl;
	size_t	dstl;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	i = dstl;
	j = 0;
	if (dstsize == 0)
		return (srcl);
	if (dstsize < dstl)
		return (srcl + dstsize);
	else
	{
		while (src[j] && (dstl + j) < dstsize)
			dst[i++] = src[j++];
		if ((dstl + j) == dstsize && dstl < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (srcl + dstl);
	}
}
