/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:24 by bcayir            #+#    #+#             */
/*   Updated: 2022/12/12 00:36:34 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

int	main(int ac, char **av)
{
	t_state	*aristo;

	aristo = malloc(sizeof(t_state));
	if (!aristo)
		return (0);
	if (ac != 5 && ac != 6)
		ft_exit("Bad number of arg...");
	ft_init(aristo, ac, av, 0);
	create_thread(aristo, -1, -1);
	return (0);
}
