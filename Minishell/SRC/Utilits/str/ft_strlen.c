/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:04:22 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:04:22 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Karakter dizisinin boyutunu alir.
*/

size_t	ft_strlen(char *ptr)
{
	size_t	count;

	count = 0;
	while (ptr && *(ptr++))
		count++;
	return (count);
}
