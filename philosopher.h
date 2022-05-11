/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 04:01:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/05/06 23:26:56 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include <pthread.h>

# define ERROR -1
# define OK 0
# define END 0

typedef struct s_philo	t_philo;
typedef struct s_amphi	t_amphi;

struct s_philo
{
	unsigned int ref;
	pthread_mutex_t *fork;
	int tte;
	int tts;
	int ttt;
	int num;
};

struct s_amphi
{
	t_philo *tab_philo;
	int tte;
	int tts;
	int ttt;
	pthread_mutex_t *aff;
};

int	verif_param(int ac, char **av);
int	ft_strlen(char *s);
#endif