/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:28:42 by akefeder          #+#    #+#             */
/*   Updated: 2022/06/23 17:28:33 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"
int	set_cour(t_amphi *cour)
{
	cour->tab_philo = NULL;
	cour->nbr_philo = 0;
	cour->ttd = 0;
	cour->tte = 0;
	cour->tts = 0;
	cour->nbr_eat = 0;
	return (OK);
}

int verif_param(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (ft_strlen(av[i]) > 10)
			return (ERROR);
		while(av[i][j] != '\0')
		{
			if (!(av[i][j] > 47 && av[i][j] < 58))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (OK);
}

int	charg_philo(t_amphi *cour)
{
	int i;

	i = 0;
	cour->tab_philo = malloc ((cour->nbr_philo + 1) * sizeof(t_philo));
	if (cour->tab_philo == NULL)
		return (ERROR);
	while (i < cour->nbr_philo)
	{
		cour->tab_philo[i].ttd = cour->ttd;
		cour->tab_philo[i].tte = cour->tte;
		cour->tab_philo[i].tts = cour->tts;
		cour->tab_philo[i].num = i;
		cour->tab_philo[i].fork_g = cour->forks[i];
		if ((i + 1) == cour->nbr_philo)
			cour->tab_philo[i].fork_d = cour->forks[0];
		else
			cour->tab_philo[i].fork_d = cour->forks[i + 1];
		i++;
	}
	return (OK);
}

int charg_forks(t_amphi* cour)
{
	int	i;

	i = 0;
	cour->forks = malloc ((cour->nbr_philo + 1) * sizeof(pthread_mutex_t));
	if (cour->forks == NULL)
		return (ERROR);
	while(i < cour->nbr_philo)
	{
		if (pthread_mutex_init (&cour->forks[i], NULL) != 0)
				return (ERROR);
		i++;
	}
	return (OK);
}

int	prepa_cour(char **av, int ac, t_amphi *cour)
{

	cour->nbr_philo = ft_atoi(av[1]);
	if (cour->nbr_philo > 200)
		return (ERROR);
	cour->ttd = ft_atoi(av[2]);
	cour->tte = ft_atoi(av[3]);
	cour->tts = ft_atoi(av[4]);
	if (ac == 6)
		cour->nbr_eat = ft_atoi(av[5]);
	if(cour->nbr_philo == ERROR || cour->ttd == ERROR || cour->tte == ERROR || cour->tts == ERROR || cour->nbr_eat == ERROR)
		return (ERROR);
	if (charg_forks(cour) == ERROR)
		return (ERROR);
	if (charg_philo(cour) == ERROR)
		return (ERROR);
	return (OK);
}