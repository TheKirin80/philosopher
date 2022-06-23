/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:57:32 by akefeder          #+#    #+#             */
/*   Updated: 2022/06/23 17:54:21 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int r_eating()
{
	return (OK);
}

int r_sleeping()
{
	return (OK);
}

int r_thinking()
{
	return (OK);
}

int r_death()
{
	return (OK);
}

void *routine(void *philo)
{
	int i;
	t_philo r_philo;

	r_philo = *(t_philo *)philo;
	i = 0;
	while (i < 10000)
		i++;
	printf("%i\n", r_philo.num);
	return (OK);
}