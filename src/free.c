/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:56:44 by akefeder          #+#    #+#             */
/*   Updated: 2022/06/13 18:49:07 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void freetime(t_amphi *cour)
{
	int i;

	i = 0;
	while (i < cour->nbr_philo)
	{
		pthread_mutex_destroy(&cour->forks[i]);
		i++;
	}
	free(cour->forks);
	free(cour->tab_philo);

	
}