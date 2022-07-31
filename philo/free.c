/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:56:44 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 21:39:34 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_forks(t_amphi *cour, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&cour->forks[j]);
		j++;
	}
	free(cour->forks);
}

void	free_mutex(t_amphi *cour)
{
	if (cour->err != 4)
	{
		pthread_mutex_destroy(&cour->m_aff);
		if (cour->err != 5)
		{
			pthread_mutex_destroy(&cour->m_finish);
			if (cour->err != 6)
				pthread_mutex_destroy(&cour->m_lastmeal);
		}
	}
}

void	free_pth(t_amphi *cour)
{
	free(cour->ref);
	free(cour->tab_philo);
}

void	freetime(t_amphi *cour)
{	
	if (cour->err != 1)
	{	
		if (cour->err != 2)
		{
			free_forks(cour, cour->nbr_philo);
			if (cour->err != 0)
				free(cour->tab_philo);
			if (cour->err != 3)
				free_mutex(cour);
		}
	}
	if (cour->err == 0)
	{
		free_pth(cour);
	}
}
