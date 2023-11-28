/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:39:41 by erigolon          #+#    #+#             */
/*   Updated: 2023/11/08 16:18:02 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "color_msg.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_philo
{
	struct s_table	*table;
	pthread_t		th;
	int				id;
	int				meals_count;
	int				eating;
	u_int64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;

}	t_philo;

typedef struct s_table
{
	int				n_of_philo;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	int				n_of_meals;
	int				death;
	int				end_meals;
	u_int64_t		start_time;
	pthread_t		*th_id;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_table;

// Parameters Checker
int			check_args(int argc, char **argv);

int			init(t_table *table, int argc, char **argv);

int			init_thread(t_table *table);

void		messages(t_philo *philo, char *message);
void		eat(t_philo *philo);

// Useful Functions
long int	ft_atoi(const char *str);
int			ft_usleep(useconds_t time, t_philo *philo);
int			ft_usleep_2(useconds_t time);
u_int64_t	get_time(void);
int			ft_strcmp(char *s1, char *s2);

#endif