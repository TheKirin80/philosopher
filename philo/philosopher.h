/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 04:01:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/07/31 21:15:25 by akefeder         ###   ########.fr       */
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
	int				fork_g;
	int				fork_d;
	int				ttd;
	int				tte;
	int				tts;
	int				num;
	unsigned long	lastmeal;
	t_amphi			*amphi;
};

struct s_amphi
{
	t_philo			*tab_philo;
	int				nbr_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nbr_eat;
	unsigned long	begin;
	int				finish;
	int				err;
	pthread_t		*ref;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_aff;
	pthread_mutex_t	m_finish;
	pthread_mutex_t	m_lastmeal;
};

int				verif_param(int ac, char **av);
int				ft_strlen(char *s);
int				ft_atoi(char *str);
int				set_cour(t_amphi *cour);
int				prepa_cour(char **av, int ac, t_amphi *cour);
void			free_forks(t_amphi *cour, int i);
void			freetime(t_amphi *cour);
void			*routine(void *philo);
void			affichage(t_philo *philo, char *message);
unsigned long	timestamp_in_ms(void);
void			mysleep(unsigned long i, t_amphi *cour);
int				get_finish(t_amphi *cour);
void			set_finish(t_amphi *cour, int i);
unsigned long	get_lastmeal(t_amphi *cour, int ref);
void			set_lastmeal(t_amphi *cour, int ref);
void			lock_forks(t_philo *philo);
void			unlock_forks(t_philo *philo);
int				r_death(t_amphi *cour);
#endif