/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:35:28 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/28 15:36:01 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void affichage(t_philo *philo, char *message)
{
	unsigned long time;
	
	pthread_mutex_lock(&philo->amphi->m_aff);
	time = timestamp_in_ms() - philo->amphi->begin;
	if (get_finish(philo->amphi) == 0)
		printf("%lu %i %s\n", time, philo->num, message); // a voir 
	pthread_mutex_unlock(&philo->amphi->m_aff);
}