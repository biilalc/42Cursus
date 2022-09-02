/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@42Kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:43:40 by bcayir            #+#    #+#             */
/*   Updated: 2022/02/13 15:43:46 by bcayir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*final;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	final = (char *) malloc(sizeof(char) * (len + 1));
	if (!final)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		final[i] = s1[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
