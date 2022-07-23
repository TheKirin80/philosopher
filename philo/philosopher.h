/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 04:01:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/24 00:28:11 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR -1
# define OK 0
# define END 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DEATH 5

typedef struct s_philo	t_philo;
typedef struct s_amphi	t_amphi;

struct s_philo
{
	pthread_t ref;
	pthread_mutex_t fork_g;
	pthread_mutex_t fork_d;
	int ttd;
	int tte;
	int tts;
	int num;
	t_amphi *amphi;
};

struct s_amphi
{
	t_philo *tab_philo;
	int nbr_philo;
	int ttd;
	int tte;
	int tts;
	int nbr_eat;
	long long begin;
	pthread_mutex_t *time;
	pthread_mutex_t *forks;
	pthread_mutex_t *aff;
};

int	verif_param(int ac, char **av);
int	ft_strlen(char *s);
int ft_atoi(char *str);
int	set_cour(t_amphi *cour);
int	prepa_cour(char **av, int ac, t_amphi *cour);
void free_forks(t_amphi *cour, int i);
void freetime(t_amphi *cour, int i);
void	*routine(void *philo);
void affichage(t_philo *philo, char *message);
long long	timestamp_in_ms();
void mysleep(int i);
#endif