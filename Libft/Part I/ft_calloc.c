/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@42Kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:42:20 by bcayir            #+#    #+#             */
/*   Updated: 2022/02/13 15:42:27 by bcayir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*final;

	final = (void *) malloc(size * count);
	if (!final)
		return (NULL);
	ft_bzero(final, count * size);
	return (final);
}
