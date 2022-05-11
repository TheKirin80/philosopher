/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:34:58 by akefeder          #+#    #+#             */
/*   Updated: 2022/05/06 23:23:30 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}

void	affichage_fi(t_philo philo, int timestamp_in_ms, int code)
{
	if (code == FORK)
	printf("%i %i has taken a fork", timestamp_in_ms, philo.num);
	if (code == EAT)
	printf("%i %i is eating", timestamp_in_ms, philo.num);
	if (code == SLEEP)
	printf("%i %i is sleeping", timestamp_in_ms, philo.num);
	if (code == THINK)
	printf("%i %i is thinking", timestamp_in_ms, philo.num);
	if (code == DEATH)
	printf("%i %i died", timestamp_in_ms, philo.num);
	printf("\n");
}