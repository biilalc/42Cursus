/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SynaxCheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:00:59 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:00:59 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_check(void)
{
	t_lexlist	*lex_list;
	int			syntax_error;

	lex_list = g_core.lex_table;
	while (lex_list)
	{
		syntax_error = syntax_error_check(lex_list);
		if (syntax_error == -1)
			break ;
		else if (!syntax_error)
			continue ;
		if (g_core.lex_table)
			lex_list = lex_list->next;
		else
			lex_list = NULL;
	}
}

int	syntax_error_check(t_lexlist *lex_list)
{
	int	pipe_error;

	if (lex_list == g_core.lex_table && lex_list->type == SIGN_PIPE)
	{
		print_lex_error(lex_list);
		return (-1);
	}
	else if (lex_list->type != TEXT && lex_list->type != SIGN_PIPE)
	{
		if (!file_error_check(lex_list))
			return (-1);
	}
	else if (lex_list->type == SIGN_PIPE)
	{
		pipe_error = pipe_error_check(lex_list);
		if (pipe_error < 0)
			return (0);
		else if (!pipe_error)
			return (-1);
	}
	return (1);
}
/*
	39: komut satırına girilen ilk şey pipe ise hata verecek
	(if'in içindeki eşitlik kontrolünün sebebi şu; 
	20. satırda lex_table'daki elemanları lex_list'e attık, şimdilik ikisinin de
	değerleri aynı fakat while döngüsüne girince 29. satırda lex_list'in next'i
	başa geliyor ve ilk elemanı lex_table'ın ilk elemanından farklı oluyor.
	Bu yüzden ilk elemana özel eşitlik kontrolü yapıyoruz.)
	44: pipe ve text dışındaki tüm türlerin hata kontrolü burada yapılır
	49: ilk eleman dışındaki tüm pipe'ların kontrolü burada yapılır
*/