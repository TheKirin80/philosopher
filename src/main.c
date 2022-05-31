/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:15:25 by akefeder          #+#    #+#             */
/*   Updated: 2022/05/31 16:37:01 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int main(int ac, char **av)
{
	t_amphi cour;

	//cour = (t_amphi){0};
	if (((ac < 5) || (ac > 6)) || (verif_param(ac, av)) == ERROR)
		return(printf("t'es mauvais chef\n"), 0);
	if (set_cour(&cour) == ERROR || prepa_cour(av, ac, &cour) == ERROR)
		return(printf("t'es mauvais chef\n"), 0);
	
	return (0);
}

