/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:57:32 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/16 19:48:09 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int r_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->amphi->aff);
	affichage(philo, "je mange");
	pthread_mutex_unlock(philo->amphi->aff);
	return (OK);
}

int r_sleeping()
{
	return (OK);
}

int r_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->amphi->aff);
	affichage(philo, "je pense");
	pthread_mutex_unlock(philo->amphi->aff);
	return (OK);
}

int r_death()
{
	return (OK);
}

void *routine(void *philo)
{
	int i;
	t_philo *r_philo;

	r_philo = (t_philo *)philo;
	i = 0;
	while (i < 50)
	{
		if (i%2 == 0)
		{
			if (r_eating(r_philo) == 1)
				printf("error in %i with eating\n", r_philo->num);
		}
		else
		{
			if (r_thinking(r_philo) == 1)
				printf("error in %i with thinking\n", r_philo->num); 
		}
		i++;
	}
	printf("Je suis le numero : %i\n", r_philo->num);
	return (OK);
}