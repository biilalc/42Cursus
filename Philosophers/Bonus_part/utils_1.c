/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:02:39 by bcayir            #+#    #+#             */
/*   Updated: 2022/12/10 20:03:53 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_exit(char *s)
{
	printf("%s", s);
	exit(0);
}

void	*waitp(void *data)
{
	int		idx;
	int		res;
	t_state	*all;

	idx = -1;
	all = (t_state *)data;
	while (true)
	{
		waitpid(-1, &res, 0);
		if (res != 0)
		{
			while (++idx < all->number_of)
				kill(all->philo[idx].pid, SIGKILL);
			break ;
		}
		usleep(100);
	}
	sem_close(all->forks);
	sem_close(all->print);
	sem_unlink("./forks");
	sem_unlink("./print");
	return (NULL);
}

void	pass_the_time(int time, t_state *all)
{
	uint64_t	start;

	start = gettime();
	while (all->is_died == false)
	{
		if (gettime() - start >= time)
			break ;
		usleep(100);
	}
}
