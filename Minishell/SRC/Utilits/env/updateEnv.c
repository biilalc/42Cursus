/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UpdateEnv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:03:29 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:03:29 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_env(char *env_name, char *new_arg)
{
	t_env	*env;

	env = g_core.env_table;
	while (env)
	{
		if (str_compare(env->env_name, env_name))
		{
			if (env->content)
				free(env->content);
			env->content = NULL;
			if (!new_arg)
				return (1);
			own_strjoin(&env->content, new_arg);
			return (1);
		}
		env = env->next;
	}
	return (0);
}
