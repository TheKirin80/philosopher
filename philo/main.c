/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:15:25 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/24 00:21:27 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int run_thread(t_amphi *cour)
{
	int	i;

	i = 0;
	while (i < cour->nbr_philo)
	{
		pthread_create (&cour->tab_philo[i].ref, NULL, routine, &cour->tab_philo[i]);
		i++;
	}
	i = 0;
	while (i < cour->nbr_philo)
	{
		pthread_join(cour->tab_philo[i].ref, NULL);
		i++;
	}
	return (OK);
}


int main(int ac, char **av)
{
	t_amphi cour;

	//cour = (t_amphi){0};
	if (((ac < 5) || (ac > 6)) || (verif_param(ac, av)) == ERROR)
		return(printf("t'es mauvais chef\n"), 0);
	if (set_cour(&cour) == ERROR || prepa_cour(av, ac, &cour) == ERROR)
		return(freetime(&cour, ERROR),printf("t'es mauvais chef\n"), 0);
	cour.begin = timestamp_in_ms();
	if (run_thread(&cour) == ERROR)
		return (freetime(&cour, 0), 0);
	printf("timestamp = %lld\n", timestamp_in_ms() - cour.begin);
	return (freetime(&cour, 0), 0);
	
}

