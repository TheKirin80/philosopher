/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:28:42 by akefeder          #+#    #+#             */
/*   Updated: 2022/05/24 20:35:56 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"
int	set_cour(t_amphi *cour)
{
	*tab_philo = NULL;
	nbr_philo = 0;
	ttd = 0;
	tte = 0;
	tts = 0;
	nbr_eat = 0;
}

int verif_param(int ac, char **av, )
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

int	prepa_cour(char **av, int ac, t_amphi *cour)
{
	cour->nbr_philo = ft_atoi(av[1]);
	cour->ttd = ft_atoi(av[2]);
	cour->tte = ft_atoi(av[3]);
	cour->tts = ft_atoi(av[4]);
	if (ac == 6)
		cour->nbr_eat = ft_atoi(av[5]);
	if(cour->nbr_philo == ERROR || cour->ttd == ERROR || cour->tte == ERROR || cour->tts == ERROR || cour->nbr_eat == ERROR)
		return (ERROR);
	return (OK);
}