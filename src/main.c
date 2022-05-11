/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:15:25 by akefeder          #+#    #+#             */
/*   Updated: 2022/05/06 21:02:10 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int main(int ac, char **av)
{
	t_amphi cour;

	if ((ac < 5) || (ac > 6) || (verif_param(ac, av)))
		return(printf("t'es mauvais chef\n"), 0);
	if (prepa_param(av, ac, ))
	return (0);
}

