/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:57:32 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 20:08:36 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int r_eating(t_philo *philo)
{
	// if (timestamp_in_ms() - philo->amphi->begin > 10000)
	// 	set_finish(philo->amphi, 1);
	lock_forks(philo);
	affichage(philo, "is eating");
	set_lastmeal(philo->amphi, (philo->num) - 1);
	mysleep((unsigned long)philo->tte, philo->amphi);
	unlock_forks(philo);
	return (OK);
}

int r_sleeping(t_philo *philo)
{
	affichage(philo, "is sleeping");
	mysleep((unsigned long)philo->tts, philo->amphi);
	affichage(philo, "is thinking");
	return (OK);
}

int r_death(t_amphi *cour)
{
	int	i;
	unsigned long rep;

	i = 0;
	rep = 0;
	while (i < cour->nbr_philo && get_finish(cour) == 0)
	{
		rep = timestamp_in_ms() - get_lastmeal(cour, i);
		if (rep > (unsigned long)cour->ttd)
		{
			printf("rep = %lu, num_philo = %i\n", rep, cour->tab_philo[i].num);
			affichage(&cour->tab_philo[i], "died");
			set_finish(cour, 1);
		}
		i++;
	}
	return (OK);
}

void *routine(void *philo)
{
	int i;
	t_philo *r_philo;

	r_philo = (t_philo *)philo;
	i = 0;
	if ((r_philo->num)%2 == 0)
		mysleep((unsigned long)(r_philo->tte/2), r_philo->amphi);
	while (get_finish(r_philo->amphi)== 0)
	{
		if (r_eating(r_philo) == 1)
			i = 0;
		if (r_sleeping(r_philo) == 1)
			i = 0;
	}
	return (OK);
}