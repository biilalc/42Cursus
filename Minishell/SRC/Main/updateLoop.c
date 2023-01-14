/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UpdateLoop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:01:25 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:01:25 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_loop(void)
{
	update_exec_output();
	g_core.is_read_arg = 0;
}

void	update_history(char *cmd)
{
	char	*ptr;

	if (!cmd)
		return ;
	ptr = cmd;
	trim_spaces(&ptr);
	if (!*ptr)
		return ;
	add_history(cmd);
}

void	update_exec_output(void)
{
	g_core.old_exec_output = g_core.old_exec_output ^ g_core.exec_output;
	g_core.exec_output = g_core.old_exec_output ^ g_core.exec_output;
	g_core.old_exec_output = g_core.old_exec_output ^ g_core.exec_output;
	g_core.exec_output = 0;
}
