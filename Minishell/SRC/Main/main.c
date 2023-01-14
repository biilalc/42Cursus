/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:01:16 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/12 12:58:01 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	init_core(env);
	signal(SIGINT, &sig_handler);
	while (1)
	{
		update_loop();
		g_core.cmd = readline(g_core.title.full_title);
		exit_signal_check();
		lexer();
		expander();
		parser();
		executer();
		update_history(g_core.cmd);
		free_for_loop();
	}
	free_core();
}
