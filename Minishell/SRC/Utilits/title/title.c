/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:04:54 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:04:54 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_title(void)
{
	char	cwd[256];

	if (g_core.title.full_title)
		free(g_core.title.full_title);
	g_core.title.full_title = NULL;
	own_strjoin(&g_core.title.full_title, g_core.title.head);
	own_strjoin(&g_core.title.full_title, (char *)getcwd(cwd, 256));
	own_strjoin(&g_core.title.full_title, "$ ");
}

/*
	burada her dongunun basinda yazilacak prompt olusturulur
	env'den expand edilerek yapilir.
*/
void	set_title(void)
{
	char	cwd[256];

	g_core.title.head = NULL;
	g_core.title.full_title = NULL;
	expand_envs(&g_core.title.head, "LOGNAME");
	str_addchar(&g_core.title.head, '@');
	expand_envs(&g_core.title.head, "NAME");
	str_addchar(&g_core.title.head, ':');
	own_strjoin(&g_core.title.full_title, g_core.title.head);
	own_strjoin(&g_core.title.full_title, (char *)getcwd(cwd, 256));
	own_strjoin(&g_core.title.full_title, "$ ");
}
