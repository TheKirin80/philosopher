/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 06:35:57 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/24 16:06:03 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int get_finish(t_amphi *cour)
{
	int i;

	pthread_mutex_lock(&cour->m_finish);
	i = cour->finish;
	pthread_mutex_unlock(&cour->m_finish);
	return i;
}
