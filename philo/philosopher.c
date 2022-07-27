/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:35:28 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/24 10:31:22 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void affichage(t_philo *philo, char *message)
{
	long long time;
	
	pthread_mutex_lock(&philo->amphi->m_aff);
	time = timestamp_in_ms() - philo->amphi->begin;
	if (get_finish(philo->amphi) == 0)
		printf("%lld %i %s\n", time, philo->num, message); // a voir 
	pthread_mutex_unlock(&philo->amphi->m_aff);
}