/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:01:59 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:01:59 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(void)
{
	g_core.cmd_table = NULL;
	create_cmdtable(g_core.lex_table);
	fill_cmdtable();
	create_files(g_core.cmd_table);
}
