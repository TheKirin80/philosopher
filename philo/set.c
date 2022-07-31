/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 06:36:00 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 21:01:10 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	set_finish(t_amphi *cour, int i)
{
	pthread_mutex_lock(&cour->m_finish);
	cour->finish = i;
	pthread_mutex_unlock(&cour->m_finish);
}

void	set_lastmeal(t_amphi *cour, int ref)
{
	pthread_mutex_lock(&cour->m_lastmeal);
	cour->tab_philo[ref].lastmeal = timestamp_in_ms();
	pthread_mutex_unlock(&cour->m_lastmeal);
}
