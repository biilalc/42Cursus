/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:04:07 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:04:07 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	gönderilen karakter dizisi icin heap bellekte
	yer ayrilir ve ardindan return edilir.
*/

char	*ft_strdup(char *ptr)
{
	char	*new_ptr;
	char	*return_new_ptr;

	if (!ptr)
		return (NULL);
	new_ptr = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	return_new_ptr = new_ptr;
	while (*ptr)
		*(new_ptr++) = *(ptr++);
	*new_ptr = 0;
	return (return_new_ptr);
}
