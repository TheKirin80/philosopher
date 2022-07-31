/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:57:32 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 21:39:07 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// int	r_one(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->amphi->forks[philo->fork_g]);
// 	mysleep((unsigned long)philo->ttd + 10, philo->amphi);
// 	pthread_mutex_unlock(&philo->amphi->forks[philo->fork_g]);
// 	return (OK);
// }

int	r_eating(t_philo *philo)
{
	lock_forks(philo);
	mysleep((unsigned long)philo->tte, philo->amphi);
	unlock_forks(philo);
	return (OK);
}

int	r_sleeping(t_philo *philo)
{
	affichage(philo, "is sleeping");
	mysleep((unsigned long)philo->tts, philo->amphi);
	affichage(philo, "is thinking");
	return (OK);
}

int	r_death(t_amphi *cour)
{
	int				i;
	unsigned long	rep;

	i = 0;
	while (i < cour->nbr_philo && get_finish(cour) == 0)
	{
		rep = timestamp_in_ms() - get_lastmeal(cour, i);
		if (rep > (unsigned long)cour->ttd)
		{
			affichage(&cour->tab_philo[i], "died");
			set_finish(cour, 1);
		}
		i++;
	}
	return (OK);
}

void	*routine(void *philo)
{
	t_philo	*r_philo;

	r_philo = (t_philo *)philo;
	if ((r_philo->num) % 2 == 0)
		mysleep((unsigned long)(r_philo->tte / 2), r_philo->amphi);
	while (get_finish(r_philo->amphi) == 0)
	{
		r_eating(r_philo);
		r_sleeping(r_philo);
	}
	return (OK);
}
