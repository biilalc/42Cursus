/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:01:12 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:01:12 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_core(char **env)
{
	fill_envs(env);
	set_metachars();
	set_title();
	g_core.exec_output = 0;
	g_core.old_exec_output = 0;
	g_core.main_pid = getpid();
}
