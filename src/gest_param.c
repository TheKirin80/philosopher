/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:28:42 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/29 02:20:39 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

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

int	prepa_param(char **av, int ac)
{
	
}