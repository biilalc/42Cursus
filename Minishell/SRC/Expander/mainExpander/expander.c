/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:59:41 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/13 21:22:50 by bcayir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander(void)
{
	if (g_core.exec_output == 2)
		return ;
	expand_values_from_lexlist();
	clear_void_contents();
}

/* 
	17: Lexer'da girilen komutlarda hatalı kullanım varsa ekrana hata
	mesajı yazılır, hata durumlarında exec_output'u 2 yapıyoruz. Çünkü
	komut yanlışsa expander'a girmemize gerek kalmaz. Burada da exec_outout 2 ise 
	fonksiyondan çıkıyoruz.
*/
