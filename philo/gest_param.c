/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:28:42 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 21:04:19 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	set_cour(t_amphi *cour)
{
	cour->tab_philo = NULL;
	cour->nbr_philo = 0;
	cour->ttd = 0;
	cour->tte = 0;
	cour->tts = 0;
	cour->nbr_eat = 0;
	cour->finish = 0;
	cour->err = 0;
	return (OK);
}

int	charg_philo(t_amphi *cour)
{
	int	i;

	i = 0;
	cour->tab_philo = malloc((cour->nbr_philo + 1) * sizeof(t_philo));
	if (cour->tab_philo == NULL)
		return (ERROR);
	while (i < cour->nbr_philo)
	{
		cour->tab_philo[i].ttd = cour->ttd;
		cour->tab_philo[i].tte = cour->tte;
		cour->tab_philo[i].tts = cour->tts;
		cour->tab_philo[i].num = i + 1;
		cour->tab_philo[i].fork_g = i;
		if ((i + 1) == cour->nbr_philo)
			cour->tab_philo[i].fork_d = 0;
		else
			cour->tab_philo[i].fork_d = i + 1;
		cour->tab_philo[i].amphi = cour;
		cour->tab_philo[i].lastmeal = timestamp_in_ms();
		i++;
	}
	return (OK);
}

int	charg_forks(t_amphi	*cour)
{
	int	i;

	i = 0;
	cour->forks = malloc ((cour->nbr_philo + 1) * sizeof(pthread_mutex_t));
	if (cour->forks == NULL)
		return (ERROR);
	while (i < cour->nbr_philo)
	{
		if (pthread_mutex_init (&cour->forks[i], NULL) != 0)
			return (free_forks(cour, i), ERROR);
		i++;
	}
	return (OK);
}

int	charg_mutex(t_amphi *cour)
{
	if (pthread_mutex_init(&cour->m_aff, NULL) != 0)
		return (cour->err = 4, ERROR);
	if (pthread_mutex_init(&cour->m_finish, NULL) != 0)
		return (cour->err = 5, ERROR);
	if (pthread_mutex_init(&cour->m_lastmeal, NULL) != 0)
		return (cour->err = 6, ERROR);
	return (OK);
}

int	prepa_cour(char **av, int ac, t_amphi *cour)
{
	cour->nbr_philo = ft_atoi(av[1]);
	if (cour->nbr_philo > 200 || cour->nbr_philo == 0)
		return (cour->err = 1, ERROR);
	cour->ttd = ft_atoi(av[2]);
	cour->tte = ft_atoi(av[3]);
	cour->tts = ft_atoi(av[4]);
	if (ac == 6)
		cour->nbr_eat = ft_atoi(av[5]);
	if (cour->nbr_philo == ERROR || cour->ttd == ERROR || cour->tte == ERROR
		|| cour->tts == ERROR || cour->nbr_eat == ERROR)
		return (cour->err = 1, ERROR);
	if (charg_forks(cour) == ERROR)
		return (cour->err = 2, ERROR);
	if (charg_philo(cour) == ERROR)
		return (cour->err = 3, ERROR);
	if (charg_mutex(cour) == ERROR)
		return (ERROR);
	return (OK);
}
