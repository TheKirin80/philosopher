/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:34:58 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 21:18:42 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		rendu;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		res = res * 10 + (str[i] - 48);
		if (res > 2147483647)
			return (ERROR);
		i++;
	}
	rendu = (int)res;
	return (rendu);
}

void	mysleep(unsigned long i, t_amphi *cour)
{
	unsigned long	time;

	time = timestamp_in_ms();
	while (timestamp_in_ms() - time < i && get_finish(cour) == 0)
		usleep(100);
}

unsigned long	timestamp_in_ms(void)
{
	struct timeval	tv;

	while (gettimeofday(&tv, NULL) < 0)
		gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
