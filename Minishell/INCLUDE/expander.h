/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:55:28 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 21:55:28 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "tables.h"
# include "macros.h"

//MAIN
void	expander(void);

//EXANDTEXT
void	expand_values_from_lexlist(void);
void	expand_text(t_lexlist *lex_table, int is_after_meta);

void	expand_order(char **dst, char **src);
void	expand_envs(char **dst, char *ptr);

void	expand_dollar(char **dst, char **src);
void	single_dollar(char **dst);
void	double_dollar(char **dst, char **src);
void	question_mark(char **dst, char **src);
void	expand_dollar_value(char **dst, char **src);

void	clear_void_contents(void);

//EXANDCMD
void	expand_cmd(char **dst);
void	expand_from_env_value(char **dst, char *content);
char	*get_arg_from_env_value(char **envs, char *search_arg_name);

void	print_expander(void);

#endif
