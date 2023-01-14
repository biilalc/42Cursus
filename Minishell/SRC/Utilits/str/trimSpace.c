/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TrimSpace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:04:47 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:04:47 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Gelen komutu bosluk gordukce adres uzerinde arttirir
	boylece geldigi fonksiyonda da artmis olur.
*/
size_t	trim_spaces(char **cmd_line)
{
	size_t	count;

	count = 0;
	if (!*cmd_line)
		return (count);
	while (**cmd_line == 32)
	{
		count++;
		(*cmd_line)++;
	}
	return (count);
}
