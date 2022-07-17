/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:35:28 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/17 06:13:56 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void affichage(t_philo *philo, char *message)
{
	long long time;
	
	pthread_mutex_lock(philo->amphi->time);
	time = timestamp_in_ms() - philo->amphi->begin;
	pthread_mutex_unlock(philo->amphi->time);
	printf("%lld %i %s\n", time, philo->num, message); // a voir 
}