/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:56:44 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/24 10:31:59 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void free_forks(t_amphi *cour, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&cour->forks[j]);
		j++;
	}

}

void freetime(t_amphi *cour, int i)
{
	if (i == 0)
		free_forks(cour, cour->nbr_philo);
	free(cour->forks);
	free(cour->tab_philo);
	pthread_mutex_destroy(&cour->m_aff);
	pthread_mutex_destroy(&cour->m_finish);
}

