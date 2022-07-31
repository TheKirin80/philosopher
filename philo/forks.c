/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:00:43 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 21:32:48 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	lock_forks(t_philo *philo)
{
	if ((philo->num) % 2 == 1)
	{
		pthread_mutex_lock(&philo->amphi->forks[philo->fork_g]);
		affichage(philo, "has taken a fork");
		if (philo->amphi->nbr_philo > 1)
		{
			pthread_mutex_lock(&philo->amphi->forks[philo->fork_d]);
			affichage(philo, "has taken a fork");
			affichage(philo, "is eating");
			set_lastmeal(philo->amphi, (philo->num) - 1);
		}
	}
	else
	{
		pthread_mutex_lock(&philo->amphi->forks[philo->fork_d]);
		affichage(philo, "has taken a fork");
		pthread_mutex_lock(&philo->amphi->forks[philo->fork_g]);
		affichage(philo, "has taken a fork");
		affichage(philo, "is eating");
		set_lastmeal(philo->amphi, (philo->num) - 1);
	}
}

void	unlock_forks(t_philo *philo)
{
	if ((philo->num) % 2 == 1)
	{
		pthread_mutex_unlock(&philo->amphi->forks[philo->fork_g]);
		affichage(philo, "has given a fork");
		if (philo->amphi->nbr_philo > 1)
		{
			pthread_mutex_unlock(&philo->amphi->forks[philo->fork_d]);
			affichage(philo, "has given a fork");
		}
	}
	else
	{
		pthread_mutex_unlock(&philo->amphi->forks[philo->fork_d]);
		pthread_mutex_unlock(&philo->amphi->forks[philo->fork_g]);
	}
}
