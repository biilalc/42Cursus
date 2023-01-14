/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrCompare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:04:42 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:04:42 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_compare(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	if (*str1 != 0 || *str2 != 0)
		return (0);
	return (1);
}
