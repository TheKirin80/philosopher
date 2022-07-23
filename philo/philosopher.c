/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:35:28 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/24 00:24:21 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void affichage(t_philo *philo, char *message)
{
	long long time;
	
	time = timestamp_in_ms() - philo->amphi->begin;
	printf("%lld %i %s\n", time, philo->num, message); // a voir 
}