/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:00:43 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 18:48:29 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	lock_forks(t_philo *philo)
{
	if ((philo->num) % 2 == 1)
	{
		pthread_mutex_lock(philo->fork_g);
		//affichage(philo, "has taken a left fork");
		affichage(philo, "has taken a fork");
		if (!(philo->fork_d))
		{
			pthread_mutex_lock(philo->fork_d);
			//affichage(philo, "has taken a right fork");
			affichage(philo, "has taken a fork");
		}
	}
	else
	{
		pthread_mutex_lock(philo->fork_d);
		//affichage(philo, "has taken a right fork");
		affichage(philo, "has taken a fork");
		pthread_mutex_lock(philo->fork_g);
		//affichage(philo, "has taken a left fork");
		affichage(philo, "has taken a fork");
	}
}

void	unlock_forks(t_philo *philo)
{
	if ((philo->num) % 2 == 1)
	{
		pthread_mutex_unlock(philo->fork_g);
		affichage(philo, "has given a fork");
		if (!(philo->fork_d))
		{
			pthread_mutex_unlock(philo->fork_d);
			affichage(philo, "has given a fork");
		}
	}
	else
	{
		pthread_mutex_unlock(philo->fork_d);
		pthread_mutex_unlock(philo->fork_g);
	}
}