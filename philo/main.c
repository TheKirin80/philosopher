/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:15:25 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 21:38:31 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	run_thread(t_amphi *cour)
{
	int	i;

	i = 0;
	cour->ref = malloc((cour->nbr_philo + 1) * sizeof(pthread_t));
	while (i < cour->nbr_philo)
	{
		pthread_create(&cour->ref[i], NULL, routine, &cour->tab_philo[i]);
		i++;
	}
	return (OK);
}

int	join_thread(t_amphi *cour)
{
	int	i;

	i = 0;
	while (i < cour->nbr_philo)
	{
		pthread_join(cour->ref[i], NULL);
		i++;
	}
	return (OK);
}

int	verif_param(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (ft_strlen(av[i]) > 10 || ft_strlen(av[i]) == 0)
			return (ERROR);
		while (av[i][j] != '\0')
		{
			if (!(av[i][j] > 47 && av[i][j] < 58))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (OK);
}

int	main(int ac, char **av)
{
	t_amphi	cour;

	if (((ac < 5) || (ac > 6)) || (verif_param(ac, av)) == ERROR)
		return (printf("t'es mauvais chef(fe)\n"), 0);
	if (set_cour(&cour) == ERROR || prepa_cour(av, ac, &cour) == ERROR)
		return (freetime(&cour), printf("t'es mauvais chef(fe)\n"), 0);
	cour.begin = timestamp_in_ms();
	if (run_thread(&cour) == ERROR)
		return (freetime(&cour), 0);
	while (get_finish(&cour) == 0)
	{
		usleep(8000);
		r_death(&cour);
	}
	join_thread(&cour);
	return (freetime(&cour), 0);
}
