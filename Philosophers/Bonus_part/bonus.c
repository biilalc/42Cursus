/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:03:09 by bcayir            #+#    #+#             */
/*   Updated: 2022/12/10 20:04:16 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int ac, char **av)
{
	t_state	*all;

	all = (t_state *)malloc(sizeof(t_state));
	if (ac != 5 && ac != 6)
		ft_exit("Bad number of arguman");
	init_arguments(all, ac, av);
	process(all);
}
