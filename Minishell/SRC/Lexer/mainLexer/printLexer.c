/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintLexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:00:35 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:00:35 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lexer(void)
{
	t_lexlist	*lexer_temp;

	lexer_temp = g_core.lex_table;
	printf ("~LEXER TABLE~\n");
	while (lexer_temp)
	{
		printf("{type: %d, content: %s}\n", lexer_temp->type,
			lexer_temp->content);
		lexer_temp = lexer_temp->next;
	}
	printf("\n\n");
}
