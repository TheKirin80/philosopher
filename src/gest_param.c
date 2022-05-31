/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:28:42 by akefeder          #+#    #+#             */
/*   Updated: 2022/05/31 20:50:14 by akefeder         ###   ########.fr       */
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
	cour->tab_philo = malloc ((nbr_philo + 1) * sizeof(t_philo));
	if (cour->tab_philo == ERROR)
		return (ERROR);
	while (i < cour->nbr_philo)
	{
		cour->tab_philo[i]->ttd = cour->ttd;
		cour->tab_philo[i]->tte = cour->tte;
		cour->tab_philo[i]->tts = cour->tts;
		cour->tab_philo[i]->num = i;
		
	}
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
	if (charg_philo(cour) == ERROR)
		return (ERROR);
	return (OK);
}