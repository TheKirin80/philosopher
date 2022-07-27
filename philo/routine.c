/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:57:32 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/27 21:50:43 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int r_eating(t_philo *philo)
{
	if (timestamp_in_ms() - philo->amphi->begin > 10000)
		set_finish(philo->amphi, 1);
	affichage(philo, "is thinking");
	pthread_mutex_lock(philo->fork_g);
	affichage(philo, "has taken a left fork");
	pthread_mutex_lock(philo->fork_d);
	affichage(philo, "has taken a right fork");
	affichage(philo, "is eating");
	mysleep(philo->tte);
	pthread_mutex_unlock(philo->fork_g);
	pthread_mutex_unlock(philo->fork_d);

	return (OK);
}

int r_sleeping(t_philo *philo)
{
	affichage(philo, "is sleeping");
	mysleep(philo->tts);
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
	if ((r_philo->num)%2 == 0)
		mysleep(r_philo->tte/2);
	while (get_finish(r_philo->amphi)== 0)
	{
		if (r_eating(r_philo) == 1)
			printf("error in %i with eating\n", r_philo->num);
		if (r_sleeping(r_philo) == 1)
			printf("error in %i with sleeping\n", r_philo->num);
	}
	printf("Je suis le numero : %i\n", r_philo->num);
	return (OK);
}