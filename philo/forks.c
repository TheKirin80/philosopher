/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:00:43 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/28 22:45:16 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	lock_forks(t_philo *philo)
{
	if ((philo->num) % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_g);
		affichage(philo, "has taken a left fork");
		pthread_mutex_lock(philo->fork_d);
		affichage(philo, "has taken a right fork");
	}
	else
	{
		pthread_mutex_lock(philo->fork_d);
		affichage(philo, "has taken a right fork");
		pthread_mutex_lock(philo->fork_g);
		affichage(philo, "has taken a left fork");
	}
}

void	unlock_forks(t_philo *philo)
{
	if ((philo->num) % 2 == 0)
	{
		pthread_mutex_unlock(philo->fork_g);
		pthread_mutex_unlock(philo->fork_d);
	}
	else
	{
		pthread_mutex_unlock(philo->fork_d);
		pthread_mutex_unlock(philo->fork_g);
	}
}