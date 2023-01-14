/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:58:32 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 21:58:32 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executer(void)
{
	if (!g_core.cmd_table)
		return ;
	else if (!g_core.cmd_table->next)
		run_single_command(g_core.cmd_table, NULL);
	else
		run_multiple_command(g_core.cmd_table);
}
